#ifndef __CUSTOMSOURCETREE_H_
#define __CUSTOMSOURCETREE_H_

#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>


class CustomSourceTree : public google::protobuf::compiler::SourceTree
{
public:
	CustomSourceTree();
	~CustomSourceTree();

	virtual google::protobuf::io::ZeroCopyInputStream* Open(const std::string& filename);

	virtual std::string GetLastErrorMessage();

	void MapPath(const char * virtual_path, const char * real_path);

private:
	google::protobuf::io::ZeroCopyInputStream* _loadFile(const std::string & filename, std::string * out_found_error_message);

private:
	struct Mapping {
		std::string virtual_path;
		std::string real_path;
		inline Mapping(const std::string& virtual_path_param,
			const std::string& real_path_param)
			: virtual_path(virtual_path_param), real_path(real_path_param) {}
	};
	std::vector<Mapping> _mappings;
	std::string _last_error_message;

private:
	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CustomSourceTree);
};


#endif