#include "core.h"

#include "string.h"

void initialize_core() {
	initialize_string();
	core.string = string;
}
