#pragma once
#include "Local.h"

#define SEX_UNKNOWN				0
#define SEX_MEN					1
#define SEX_WOMEN				2
#define GET_SEX_STRING_A(t)		(((t) == SEX_MEN)?("��"):(((t) == SEX_WOMEN)?("Ů"):("��")))
#define GET_SEX_STRING_W(t)		(((t) == SEX_MEN)?(L"��"):(((t) == SEX_WOMEN)?(L"Ů"):(L"��")))

#define ST_NAME_LOBBY			"LOBBY"
#define ST_NAME_LOGICAL			"LOGICAL"
