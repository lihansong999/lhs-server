#include "stdafx.h"
#include "CustomImporter.h"


CustomImporter::CustomImporter()
	:google::protobuf::compiler::Importer(&_customSourceTree, &_customMultiFileErrorCollector)
{

}

CustomImporter::~CustomImporter()
{

}

google::protobuf::Message * CustomImporter::NewDynamicMessage(const std::string& name)
{
	google::protobuf::Message * ret = nullptr;
	const google::protobuf::Descriptor* descriptor = pool()->FindMessageTypeByName(name);
	if (descriptor)
	{
		const google::protobuf::Message * message = _dynamicMessageFactory.GetPrototype(descriptor);
		if (message)
		{
			ret = message->New();
		}
	}
	return ret;
}

CustomSourceTree * CustomImporter::GetCustomSourceTree()
{
	return &_customSourceTree;
}

CustomMultiFileErrorCollector * CustomImporter::GetCustomMultiFileErrorCollector()
{
	return &_customMultiFileErrorCollector;
}