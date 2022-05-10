#include "arguments.h"

#include "../core/core.h"

#include <stdbool.h>

ArgumentsFunctions arguments_functions;

bool tui_arguments_is_flag(int argc, char** argv, char character) {
	int index = 0;
	while (index < argc) {
		int length = core.string.get_length(argv[index]);
		if (length == 2 && argv[index][0] == '-' && argv[index][1] == character) {
			return true;
		}
		index++;
	}
	return false;
}

void tui_arguments_initialize() {
	arguments_functions.is_flag = &tui_arguments_is_flag;
}
