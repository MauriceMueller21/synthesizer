#pragma once

#include "args.h"

typedef struct Tui {
	Args args;
} Tui;

extern Tui tui;

void tui_initialize();
