#pragma once

#include <stdbool.h>

typedef struct {
	char* (*bool_to_string)(bool boolean);
	int (*index_of)(char* string, char character);
} String;

String string;

void initialize_string();
