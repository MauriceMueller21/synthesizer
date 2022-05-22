#include "core/core.h"
#include "sound/sound.h"
#include "gui/gui.h"
#include "gui/widget.h"

void print_hello()
{
	gui.print("Hello :D\n");
}

void print_angry()
{
	gui.print("Ey :o\n");
}

void synthesizer()
{
	CreateWidget(Window, "main-window").params("Synthesizer", 500, 500)
	(
		CreateWidget(Layout).params("vertical")
		(
			CreateWidget(Button, "a").params("Click me!", print_hello),
			CreateWidget(Button, "b").params("Do not click me!", print_angry),
			SENTINAL
		)
	);
}

int main(int argc, char** argv)
{
	core_initialize();
	sound_initialize();
	initialize_gui_syntax();
	gui.init("de.synthesizer.gui", synthesizer);
	return gui.run(argc, argv);
}

