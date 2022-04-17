#pragma once

#include "args.h"

typedef struct Tui {
	Args args;
} Tui;

Tui tui;

void tui_initialize();
