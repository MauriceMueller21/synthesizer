#pragma once

#include <stdbool.h>

typedef struct {
	char* (*bool_to_string)(bool boolean);
	int (*index_of)(char* string, char character);
} Core;

Core core;
