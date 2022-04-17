#include "tui.h"

#include "args.h"

void tui_initialize() {
	tui_args_initialize();
	tui.args = args;
}
