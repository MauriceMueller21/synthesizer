#include "core/core.h"
#include "sound/sound.h"
#include "gui/gui.h"

void populate_syntax()
{
	core_initialize();
	sound_initialize();
	gui_initialize();
}

void synthesizer()
{
	gui.create("Synthesizer", 300, 300);
	// gui.layout.create("vertical");
	// gui.button.create();
	// gui.button.create();
	// gui.layout.finish();
}

int main(int argc, char** argv)
{
	populate_syntax();
	gui.init("de.synthesizer.gui", synthesizer);
	return gui.run(argc, argv);
}

