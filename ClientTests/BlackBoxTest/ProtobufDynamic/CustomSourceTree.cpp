#include "stdafx.h"
#include "CustomSourceTree.h"
#include <sstream>


class CustomIstreamInputStream : public google::protobuf::io::IstreamInputStream
{
public:
	CustomIstreamInputStream(std::istream* input)
		:google::protobuf::io::IstreamInputStream(input, -1), _input(input) {};
	~CustomIstreamInputStream() { if (_input)delete _input; }
private:
	std::istream* _input;
private:
	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CustomIstreamInputStream);
};

static inline char LastChar(const std::string& str) {
	return str[str.size() - 1];
}

static std::string CanonicalizePath(std::string path) {
#ifdef _WIN32
	// The Win32 API accepts forward slashes as a path delimiter even though
	// backslashes are standard.  Let's avoid confusion and use only forward
	// slashes.
	if (google::protobuf::HasPrefixString(path, "\\\\")) {
		// Avoid converting two leading backslashes.
		path = "\\\\" + google::protobuf::StringReplace(path.substr(2), "\\", "/", true);
	}
	else {
		path = google::protobuf::StringReplace(path, "\\", "/", true);
	}
#endif

	std::vector<std::string> canonical_parts;
	std::vector<std::string> parts = google::protobuf::Split(
		path, "/", true);  // Note:  Removes empty parts.
	for (int i = 0; i < (int)parts.size(); i++) {
		if (parts[i] == ".") {
			// Ignore.
		}
		else {
			canonical_parts.push_back(parts[i]);
		}
	}
	std::string result = google::protobuf::Join(canonical_parts, "/");
	if (!path.empty() && path[0] == '/') {
		// Restore leading slash.
		result = '/' + result;
	}
	if (!path.empty() && LastChar(path) == '/' && !result.empty() &&
		LastChar(result) != '/') {
		// Restore trailing slash.
		result += '/';
	}
	return result;
}

static inline bool ContainsParentReference(const std::string& path) {
	return path == ".." || google::protobuf::HasPrefixString(path, "../") ||
		google::protobuf::HasSuffixString(path, "/..") || path.find("/../") != std::string::npos;
}

static bool IsWindowsAbsolutePath(const std::string& text) {
#if defined(_WIN32) || defined(__CYGWIN__)
	return text.size() >= 3 && text[1] == ':' && isalpha(text[0]) &&
		(text[2] == '/' || text[2] == '\\') && text.find_last_of(':') == 1;
#else
	return false;
#endif
}

static bool ApplyMapping(const std::string& filename,
	const std::string& old_prefix,
	const std::string& new_prefix, std::string* result) {
	if (old_prefix.empty()) {
		// old_prefix matches any relative path.
		if (ContainsParentReference(filename)) {
			// We do not allow the file name to use "..".
			return false;
		}
		if (google::protobuf::HasPrefixString(filename, "/") || IsWindowsAbsolutePath(filename)) {
			// This is an absolute path, so it isn't matched by the empty string.
			return false;
		}
		result->assign(new_prefix);
		if (!result->empty()) result->push_back('/');
		result->append(filename);
		return true;
	}
	else if (google::protobuf::HasPrefixString(filename, old_prefix)) {
		// old_prefix is a prefix of the filename.  Is it the whole filename?
		if (filename.size() == old_prefix.size()) {
			// Yep, it's an exact match.
			*result = new_prefix;
			return true;
		}
		else {
			// Not an exact match.  Is the next character a '/'?  Otherwise,
			// this isn't actually a match at all.  E.g. the prefix "foo/bar"
			// does not match the filename "foo/barbaz".
			int after_prefix_start = -1;
			if (filename[old_prefix.size()] == '/') {
				after_prefix_start = old_prefix.size() + 1;
			}
			else if (filename[old_prefix.size() - 1] == '/') {
				// old_prefix is never empty, and canonicalized paths never have
				// consecutive '/' characters.
				after_prefix_start = old_prefix.size();
			}
			if (after_prefix_start != -1) {
				// Yep.  So the prefixes are directories and the filename is a file
				// inside them.
				std::string after_prefix = filename.substr(after_prefix_start);
				if (ContainsParentReference(after_prefix)) {
					// We do not allow the file name to use "..".
					return false;
				}
				result->assign(new_prefix);
				if (!result->empty()) result->push_back('/');
				result->append(after_prefix);
				return true;
			}
		}
	}

	return false;
}

CustomSourceTree::CustomSourceTree()
{

}

CustomSourceTree::~CustomSourceTree()
{

}

google::protobuf::io::ZeroCopyInputStream* CustomSourceTree::Open(const std::string& filename)
{
	if (filename != CanonicalizePath(filename) ||
		ContainsParentReference(filename)) {
		_last_error_message =
			"Backslashes, consecutive slashes, \".\", or \"..\" "
			"are not allowed in the virtual path";
		return nullptr;
	}
	std::string temp_error_message;
	for (int i = 0; i < (int)_mappings.size(); i++) {
		std::string temp_disk_file;
		if (ApplyMapping(filename, _mappings[i].virtual_path,
			_mappings[i].real_path, &temp_disk_file)) {
			temp_error_message = "";
			google::protobuf::io::ZeroCopyInputStream* stream = _loadFile(temp_disk_file, &temp_error_message);
			if (stream != nullptr) {
				return stream;
			}
			if (temp_error_message.compare("") != 0) {
				_last_error_message = temp_error_message;
				return nullptr;
			}
		}
	}
	_last_error_message = "File not found.";
	return nullptr;
}

std::string CustomSourceTree::GetLastErrorMessage()
{
	//return google::protobuf::compiler::SourceTree::GetLastErrorMessage();
	return _last_error_message;
}

void CustomSourceTree::MapPath(const char * virtual_path, const char * real_path)
{
	_mappings.push_back(Mapping(virtual_path, CanonicalizePath(real_path)));
}

google::protobuf::io::ZeroCopyInputStream* CustomSourceTree::_loadFile(const std::string & filename, std::string * out_found_error_message)
{
	FILE * filePointer = nullptr;
	errno_t err = 0;
	do {
		err = fopen_s(&filePointer, filename.c_str(), "rb");
	} while (!filePointer && err == EINTR);
	if (!filePointer && err == EACCES)
	{
		*out_found_error_message = "Read access is denied for file: " + filename;
		return nullptr;
	}
	if (filePointer)
	{
		fseek(filePointer, 0, SEEK_END);
		long filesize = ftell(filePointer);
		fseek(filePointer, 0, SEEK_SET);
		if (filesize <= 0L)
		{
			fclose(filePointer);
			return new CustomIstreamInputStream(new std::stringstream());
		}
		char * buffer = new char[filesize];
		size_t c = fread(buffer, 1, filesize, filePointer);
		if (ferror(filePointer) || c != (size_t)filesize)
		{
			delete[] buffer;
			fclose(filePointer);
			*out_found_error_message = "fread() error for file: " + filename;
			return nullptr;
		}
		std::stringstream * stream = new std::stringstream();
		stream->write(buffer, filesize);
		delete[] buffer;
		fclose(filePointer);
		return new CustomIstreamInputStream(stream);
	}
	return nullptr;
}