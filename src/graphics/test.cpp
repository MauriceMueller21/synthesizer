#include "test.h"
#include "components/window.h"
#include <X11/Xlib.h>

int test_graphics_manually()
{
	SWindow window;
	window["title"] = std::string("Synthesizer");
	window["width"] = 600;
	window["height"] = 400;
	window.create();

	XEvent event;
	while(true)
	{
		XNextEvent(window.display(), &event);
	}

	return 0;
}

