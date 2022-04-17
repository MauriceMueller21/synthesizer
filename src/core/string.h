#pragma once

#include <stdbool.h>

typedef struct String {
	char* (*bool_to_string)(bool boolean);
	char* (*concatenate_strings)(char* string1, char* string2);
	int (*index_of)(char* string, char character);
} String;

extern String string;

void core_string_initialize();
