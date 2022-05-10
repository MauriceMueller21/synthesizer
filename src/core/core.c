#include "core.h"

CoreFunctions core;

void core_initialize() {
	core_char_list_initialize();
	core.charlist = char_list_functions;
	core_file_initialize();
	core.file = file_functions;
	core_list_initialize();
	core.list = list_functions;
	core_string_initialize();
	core.string = string_functions;
	core_string_list_initialize();
	core.stringlist = string_list_functions;
}
