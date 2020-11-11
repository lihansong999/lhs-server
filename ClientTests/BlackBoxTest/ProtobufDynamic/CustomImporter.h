#ifndef __CUSTOMIMPORTER_H_
#define __CUSTOMIMPORTER_H_

#include <google/protobuf/compiler/importer.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include "CustomSourceTree.h"
#include "CustomMultiFileErrorCollector.h"


class CustomImporter : public google::protobuf::compiler::Importer
{
public:
	CustomImporter();
	~CustomImporter();

	google::protobuf::Message * NewDynamicMessage(const std::string& name);

	CustomSourceTree * GetCustomSourceTree();

	CustomMultiFileErrorCollector * GetCustomMultiFileErrorCollector();

private:
	google::protobuf::DynamicMessageFactory _dynamicMessageFactory;
	CustomSourceTree _customSourceTree;
	CustomMultiFileErrorCollector _customMultiFileErrorCollector;

private:
	GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(CustomImporter);
};


#endif