#ifndef __CUSTOMMULTIFILEERRORCOLLECTOR_H_
#define __CUSTOMMULTIFILEERRORCOLLECTOR_H_

#include <google/protobuf/compiler/importer.h>


class CustomMultiFileErrorCollector : public google::protobuf::compiler::MultiFileErrorCollector
{
public:
	CustomMultiFileErrorCollector();
	~CustomMultiFileErrorCollector();

	virtual void AddError(const std::string& filename, int line, int column, const std::string& message) override;

	virtual void AddWarning(const std::string& filename, int line, int column, const std::string& message) override;

private:
	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CustomMultiFileErrorCollector);
};


#endif