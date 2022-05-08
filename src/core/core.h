#pragma once

#include "file.h"
#include "list.h"
#include "string.h"

typedef struct Core {
	File file;
	List list;
	String string;
} Core;

extern Core core;

void core_initialize();
