#ifndef __WEBMSGPACKAGE_H__
#define __WEBMSGPACKAGE_H__

#include "../Local.h"
#include "WebMsgBase.h"


extern Message::MSGString WebMsgPackage(WebMsgBase * msg);

extern bool WebMsgUnPackage(CURLcode performCode, long responseCode, const Message::MSGString & json, WebMsgBase * msg);


#endif //!__WEBMSGPACKAGE_H__