#include "core.h"

Core core;

void core_initialize() {
	core_list_initialize();
	core.list = list;
	core_string_initialize();
	core.string = string;
}
