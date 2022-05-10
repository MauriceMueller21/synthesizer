#pragma once

typedef struct StringFunctions {
	int (*get_length)(char* string);
	char* (*get_substring)(char* string, int start, int end);
	int (*is_substring)(char* string, char* part, int position);
	int (*are_strings_equal)(char* string1, char* string2);
	int (*starts_with_string)(char* string, char* start);
	int (*ends_with_string)(char* string, char* end);
	char* (*concatenate_strings)(char* string1, char* string2);
	int (*search_character)(char* string, char character);
	char* (*boolean_to_string)(int value);
	int (*get_2_byte_little_endian)(unsigned char* array, int position);
	int (*get_4_byte_little_endian)(unsigned char* array, int position);
} StringFunctions;

extern StringFunctions string_functions;

void core_string_initialize();
