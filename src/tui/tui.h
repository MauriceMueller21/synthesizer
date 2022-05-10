#pragma once

#include "arguments.h"

typedef struct TuiFunctions {
	ArgumentsFunctions arguments;
} TuiFunctions;

extern TuiFunctions tui;

void tui_initialize();
