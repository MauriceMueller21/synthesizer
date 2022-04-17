#include "args.h"

#include <stdbool.h>
#include <string.h>

Args args;

bool tui_args_is_flag(int argc, char** argv, char character) {
	int index = 0;
	while (index < argc) {
		int length = strlen(argv[index]);
		if (length == 2 && argv[index][0] == '-' && argv[index][1] == character) {
			return true;
		}
		index++;
	}
	return false;
}

void tui_args_initialize() {
	args.is_flag = &tui_args_is_flag;
}
