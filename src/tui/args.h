#pragma once

#include <stdbool.h>

typedef struct Args {
	bool (*is_flag)(int argc, char** argv, char character);
} Args;

Args args;

void tui_args_initialize();
