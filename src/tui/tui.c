#include "tui.h"

#include "args.h"

Tui tui;

void tui_initialize() {
	tui_args_initialize();
	tui.args = args;
}
