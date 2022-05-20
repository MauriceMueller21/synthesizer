#include "core/core.h"
#include "sound/sound.h"
#include "gui/gui.h"

void print_hello_world()
{
	gui.print("Hello, world!\n");
}

void synthesizer()
{
	gui.window.create("Synthesizer", 500, 500).build()
	(
		gui.button.create("Click me!", print_hello_world).build()
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

