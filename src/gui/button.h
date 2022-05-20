#pragma once
#include "gui/widget.h"

typedef struct SButton SButton;
struct SButton
{
	/**
	 * Creates a new button inside the application with the given properties.
	 *
	 * @param label The displayed label of the button.
	 * @param callback The callback button that is called once pressed.
	 */
	SButton (*create)(char* label, void(*callback)());
	
	/**
	 * Builds the given button allowing children to be placed inside it.
	 */
	SWidget* (*build)(void);
};
extern SButton button;

/**
 * Initializes the special syntax for the button functions.
 */
void gui_button_initialize();

