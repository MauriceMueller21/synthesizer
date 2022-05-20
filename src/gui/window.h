#pragma once
#include "gui/widget.h"

typedef struct SWindow SWindow;
struct SWindow
{
	/**
	 * Creates a new window inside the application with the given properties.
	 *
	 * @param title The displayed title of the window.
	 * @param width The initial width of the window.
	 * @param height The initial height of the window.
	 */
	SWindow (*create)(char* title, int width, int height);
	
	/**
	 * Builds the given window allowing children to be placed inside it.
	 */
	SWidgetFunction (*build)();
};
extern SWindow window;

/**
 * Initializes the special syntax for the window functions.
 */
void gui_window_initialize();

