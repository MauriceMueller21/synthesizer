#pragma once

#include <stdbool.h>

typedef struct ArgumentsFunctions {
	bool (*is_flag)(int argc, char** argv, char character);
} ArgumentsFunctions;

extern ArgumentsFunctions arguments_functions;

void tui_arguments_initialize();
