#include "string.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

String string;

char* core_string_bool_to_string(bool boolean) {
	return boolean ? "true" : "false";
}

char* core_string_concatenate_strings(char* string1, char* string2) {
	int length1 = strlen(string1);
	int length2 = strlen(string2);
	int length = length1 + length2;
	char* result = malloc(sizeof(char) * length);
	int index = 0;
	while (index < length) {
		if (index < length1) {
			result[index] = string1[index];
		} else {
			result[index] = string2[index - length1];
		}
		index++;
	}
	return result;
}

int core_string_index_of(char* string, char character) {
	int index = 0;
	int length = strlen(string);
	while (index < length && string[index] != character) {
		if (string[index] == character) {
			return index;
		}
		index++;
	}
	return -1;
}

void core_string_initialize() {
	string.bool_to_string = &core_string_bool_to_string;
	string.concatenate_strings = &core_string_concatenate_strings;
	string.index_of = &core_string_index_of;
}
