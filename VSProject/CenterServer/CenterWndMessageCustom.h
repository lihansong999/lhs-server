#pragma once
#include "Classes/CenterBase/Local.h"

//print
#define WMC_BASE_BLOCK1											(WM_USER + 0)
#define WMC_PRINT_PRINT											(WMC_BASE_BLOCK1 + 1)
#define WMC_LOG_PRINT											(WMC_BASE_BLOCK1 + 2)

//tips
#define WMC_BASE_BLOCK2											(WM_USER + 100)
#define WMC_TIPS_CLOSE_SERVICE									(WMC_BASE_BLOCK2 + 1)
#define WMC_TIPS_FROM_MYSQL_RELOAD_REDIS_SCRIPT_SHA1_TO_MEMORY	(WMC_BASE_BLOCK2 + 2)

//service state
#define WMC_BASE_BLOCK3											(WM_USER + 200)
#define WMC_SSTATE_CHANGE_TO_STARTED							(WMC_BASE_BLOCK3 + 1)
#define WMC_SSTATE_CHANGE_TO_STOPPED							(WMC_BASE_BLOCK3 + 2)

//notify
#define WMC_BASE_BLOCK4											(WM_USER + 300)
#define WMC_NOTE_ONLINE_SERVER_LIST_UPDATE						(WMC_BASE_BLOCK4 + 1)