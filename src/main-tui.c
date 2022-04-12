#include "core/core.h"
#include "tui/tui.h"

#include <stdio.h>

int main(int argc, char** argv) {
	initialize_core();
	char* string1 = core.string.bool_to_string(true);
	char* string2 = core.string.bool_to_string(false);
	printf("%s\n", string1);
	printf("%s\n", string2);
	initialize_tui();
	printf("%s\n", tui.args.is_flag(argc, argv, 'a') ? "true" : "false");
	bool isASet = tui.args.is_flag(argc, argv, 'a');
	printf("%s\n", core.string.bool_to_string(isASet));
	printf("Hello World! (%d parameters, %p is the pointer)\n", argc, argv);
	return 0;
}
