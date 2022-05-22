#pragma once
#include "gui/window.h"
#include "gui/layout.h"
#include "gui/button.h"
//#include "gui/console.h"
typedef struct _GtkApplication GtkApplication;
typedef struct List WidgetList;

struct GuiFunctions
{
	SWindow window;
	SLayout layout;
	SButton button;
	//SConsole console;

	/**
	 * Initializes the gtk application.
	 *
	 * @param identifier The global unique identifier for this application.
	 * @param callback   The callback function that defines all the widgets.
	 */
	void (*init)(char* identifier, void (*callback)(int));

	/**
	 * Runs the application until it is closed.
	 *	
	 * @param argc The number of command line arguments.
	 * @param argv The list of the command line arguments.
	 * @return 	   The status code of the application.
	 */
	int (*run)(int argc, char** argv);

	/**
	 * Prints the text to the console or a widget.
	 *
	 * @param format The string that can contain format tags.
	 * @param ...    Additional parameters for each format tag.
	 */
	void (*print)(const char* format, ...);

	/**
	 * Only used internally!
	 * The Pointer to the gtk application.
	 */
	GtkApplication* app;
	
	/**
	 * Only used internally!
	 * The list that contains all the named widgets.
	 */
	WidgetList* widgets;
	
	/**
	 * Only used internally!
	 * The stack that contains all the building widgets.
	 */
	WidgetList* build_stack;
};
extern struct GuiFunctions gui;

/**
 * Initializes the special syntax for the gui functions.
 */
void initialize_gui_syntax();

