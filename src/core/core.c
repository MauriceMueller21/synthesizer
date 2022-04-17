#include "core.h"

void core_initialize() {
	core_list_initialize();
	core.list = list;
	core_string_initialize();
	core.string = string;
}
