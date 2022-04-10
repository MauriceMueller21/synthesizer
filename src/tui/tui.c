#include "tui.h"
#include "args.h"

void initialize_tui_struct() {
	tui.args = args;
}

Tui tui = {
	&initialize_tui_struct,
	{0}
};
