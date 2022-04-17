#pragma once

#include "list.h"
#include "string.h"

typedef struct Core {
	List list;
	String string;
} Core;

extern Core core;

void core_initialize();
