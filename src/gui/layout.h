#pragma once
#include "gui/widget.h"

/**
 * Enables the special syntax for layout functions.
 *
 * usage: gui.layout.create(...).build()
 */
typedef struct SLayout SLayout;
struct SLayout
{
	/**
	 * 
	 */
	SLayout (*create) (char* type);

	/**
	 * 
	 */
	SWidgetFunction (*build) ();
};
extern SLayout layout;

/**
 *
 */
void gui_layout_initialize();

