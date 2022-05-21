#include "core/core.h"
#include "sound/sound.h"
#include "gui/gui.h"

int count = 0;

void print_hello_world()
{
	count++;
	gui.print("Hello, world! #%d\n", count);
}

void print_disappointment()
{
	gui.print("I do not wanted to be clicked! :(\n");
}

void synthesizer()
{
	gui.window.create("Synthesizer", 500, 500).build()
	(
		gui.layout.create("vertical").build()
		(
			gui.button.create("Click me!", print_hello_world).build(),
			gui.button.create("Do not click me!", print_disappointment).build(),
			gui.stopper()
		)
	);
}

int main(int argc, char** argv)
{
	core_initialize();
	sound_initialize();
	gui_initialize();
	
	gui.init("de.synthesizer.gui", synthesizer);
	return gui.run(argc, argv);
}

