#include "tui.h"

#include "args.h"

void initialize_tui() {
	initialize_args();
	tui.args = args;
}
