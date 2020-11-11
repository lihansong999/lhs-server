#ifndef __SERVERCOMMON_MYSQLHELPER_H__
#define __SERVERCOMMON_MYSQLHELPER_H__

#include "SCLocal.h"

SC_NS_BEGIN


class SC_DLL MySQLHelper : public Framework::FWMySQLHelper
{
public:
	MySQLHelper();
	~MySQLHelper();

private:

};


SC_NS_END


#endif //!__SERVERCOMMON_MYSQLHELPER_H__