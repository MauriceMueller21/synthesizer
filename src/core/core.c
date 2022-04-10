#include "core.h"

#include <stdbool.h>
#include <string.h>

char* bool_to_string(bool boolean) {
	return boolean ? "true" : "false";
}

int index_of(char* string, char character) {
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

Core core = {
	&bool_to_string,
	&index_of
};
