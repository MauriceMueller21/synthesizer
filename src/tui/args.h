#pragma once

#include <stdbool.h>

typedef struct {
	bool (*is_flag)(int argc, char** argv, char character);
} Args;

Args args;
