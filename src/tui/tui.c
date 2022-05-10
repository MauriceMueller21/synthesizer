#include "tui.h"

#include "arguments.h"

TuiFunctions tui;

void tui_initialize() {
	tui_arguments_initialize();
	tui.arguments = arguments_functions;
}
