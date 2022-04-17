#include "core/core.h"
#include "tui/tui.h"

#include <stdio.h>

int main(int argc, char** argv) {
	core_initialize();
	char* string1 = core.string.bool_to_string(true);
	char* string2 = core.string.bool_to_string(false);
	char* type = "%s";
	char* pattern = core.string.concatenate_strings(type, "\n");
	printf(pattern, string1);
	printf("%s\n", string2);
	tui_initialize();
	int a = 2;
	void* ap = &a;
	ap = &core;
	int* bp = (int*)(ap);
	int b = *bp;
	printf("Pointer: %p\n", ap);
	printf("Integer: %d\n", b);
	printf("Size:    %lu\n", sizeof(ap));
	printf("%s\n", tui.args.is_flag(argc, argv, 'a') ? "true" : "false");
	bool isASet = tui.args.is_flag(argc, argv, 'a');
	printf("%s\n", core.string.bool_to_string(isASet));
	printf("Hello World! (%d parameters, %p is the pointer)\n", argc, argv);
	return 0;
}
