#pragma once

#include "char_list.h"
#include "file.h"
#include "list.h"
#include "string.h"
#include "string_list.h"
#include "time.h"

typedef struct CoreFunctions {
	CharListFunctions charlist;
	FileFunctions file;
	ListFunctions list;
	StringFunctions string;
	StringListFunctions stringlist;
	TimeFunctions time;
} CoreFunctions;

extern CoreFunctions core;

void core_initialize();
