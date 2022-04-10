#include "core/core.h"
#include "tui/tui.h"

#include <stdio.h>

int main(int argc, char** argv) {
	tui.initialize();
	char* string1 = core.bool_to_string(true);
	char* string2 = core.bool_to_string(false);
	printf("%s\n", string1);
	printf("%s\n", string2);
	printf("%s\n", core.args.is_flag(argc, argv, 'a') ? "true" : "false");
	printf("%s\n", core.bool_to_string(tui.args.is_flag(argc, argv, 'a')));
	printf("Hello World! (%d parameters, %p is the pointer)\n", argc, argv);
	return 0;
}
