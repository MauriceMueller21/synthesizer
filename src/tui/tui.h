#pragma once

#include "args.h"

#include <stdbool.h>

typedef struct {
	void (*initialize)();
	Args args;
} Tui;

Tui tui;
