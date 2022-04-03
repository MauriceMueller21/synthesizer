#include "test.h"
#include "components/window.h"
#include <X11/Xlib.h>

int test_graphics_manually()
{
	SWindow* window = new SWindow();
	window->title("Synthesizer");
	window->width(400);
	window->height(400);
	window->create();

	XEvent event;
	while(true)
	{
		XNextEvent(window->display(), &event);
	}

	delete(window);
	return 0;
}

