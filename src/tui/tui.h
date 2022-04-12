#pragma once

#include "args.h"

typedef struct {
	Args args;
} Tui;

Tui tui;

void initialize_tui();
