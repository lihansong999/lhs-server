#pragma once
#include "Local.h"

//print
#define WMC_BASE_BLOCK1											(WM_USER + 0)
#define WMC_PRINT_PRINT											(WMC_BASE_BLOCK1 + 1)
#define WMC_LOG_PRINT											(WMC_BASE_BLOCK1 + 2)

//tips
#define WMC_BASE_BLOCK2											(WM_USER + 100)
#define WMC_TIPS_CLOSE_WND										(WMC_BASE_BLOCK2 + 1)
#define WMC_TIPS_FROM_DISK_RELOAD_REDIS_SCRIPT_SHA1_TO_MYSQL	(WMC_BASE_BLOCK2 + 2)