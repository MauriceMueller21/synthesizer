#include "args.h"

#include <stdbool.h>
#include <string.h>

bool is_flag(int argc, char** argv, char character) {
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

void initialize_args() {
	args.is_flag = &is_flag;
}
