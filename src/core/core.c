#include "core.h"

Core core;

void core_initialize() {
	core_file_initialize();
	core.file = file;
	core_list_initialize();
	core.list = list;
	core_string_initialize();
	core.string = string;
}
