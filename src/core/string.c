#include "string.h"

#include <stdlib.h>

String string;

int core_string_get_length(char* string) {
	int index = 0;
	while (string[index] != 0) {
		index++;
	}
	return index;
}

char* core_string_get_substring(char* string, int start, int end) {
	int length = core_string_get_length(string);
	if (start < 0 || start >= end || start >= length || end > length) {
		return 0;
	}
	int target_length = end - start;
	char* result = malloc(target_length);
	int index = 0;
	while (index < target_length) {
		result[index] = string[index + start];
		index++;
	}
	return result;
}

int core_string_is_substring(char* string, char* part, int position) {
	int string_length = core_string_get_length(string);
	int part_length = core_string_get_length(part);
	if (position < 0 || position >= string_length) {
		return 0;
	}
	if (part_length > string_length || position + part_length > string_length) {
		return 0;
	}
	int index = 0;
	while (index < part_length) {
		if (part[index] != string[position + index]) {
			return 0;
		}
		index++;
	}
	return 1;
}

int core_string_are_strings_equal(char* string1, char* string2) {
	int index = 0;
	while (1) {
		if (string1[index] != string2[index]) {
			return 0;
		} else if (string1[index] == 0) {
			return 1;
		}
		index++;
	}
}

int core_string_starts_with_string(char* string, char* start) {
	return core_string_is_substring(string, start, 0);
}

int core_string_ends_with_string(char* string, char* end) {
	int string_length = core_string_get_length(string);
	int end_length = core_string_get_length(end);
	return core_string_is_substring(string, end, string_length - end_length);
}

char* core_string_concatenate_strings(char* string1, char* string2) {
	int length1 = core_string_get_length(string1);
	int length2 = core_string_get_length(string2);
	int length = length1 + length2 + 1;
	char* result = malloc(sizeof(char) * length);
	int index = 0;
	while (index < length - 1) {
		if (index < length1) {
			result[index] = string1[index];
		} else {
			result[index] = string2[index - length1];
		}
		index++;
	}
	result[length - 1] = 0;
	return result;
}

int core_string_search_character(char* string, char character) {
	int index = 0;
	int length = core_string_get_length(string);
	while (index < length) {
		if (string[index] == character) {
			return index;
		}
		index++;
	}
	return -1;
}

char* core_string_boolean_to_string(int value) {
	return value ? "true" : "false";
}

int core_string_get_2_byte_little_endian(unsigned char* array, int position) {
	int part1 = array[position];
	int part2 = array[position + 1];
	return 256 * part2 + part1;
}

int core_string_get_4_byte_little_endian(unsigned char* array, int position) {
	int part1 = array[position];
	int part2 = array[position + 1];
	int part3 = array[position + 2];
	int part4 = array[position + 3];
	return ((part4 * 256 + part3) * 256 + part2) * 256 + part1;
}

void core_string_initialize() {
	string.get_length = &core_string_get_length;
	string.get_substring = &core_string_get_substring;
	string.is_substring = &core_string_is_substring;
	string.are_strings_equal = &core_string_are_strings_equal;
	string.starts_with_string = &core_string_starts_with_string;
	string.ends_with_string = &core_string_ends_with_string;
	string.concatenate_strings = &core_string_concatenate_strings;
	string.search_character = &core_string_search_character;
	string.boolean_to_string = &core_string_boolean_to_string;
	string.get_2_byte_little_endian = &core_string_get_2_byte_little_endian;
	string.get_4_byte_little_endian = &core_string_get_4_byte_little_endian;
}
