#pragma once
#include "gui/widget.h"
#include "gui/window.h"
#include "gui/button.h"
#include "core/list.h"
#include <gtk/gtk.h>

typedef struct SGui SGui;
struct SGui
{
	SWindow window;
	SButton button;

	/**
	 * Initializes the gtk application and runs the given callback function once
	 * the application starts.
	 *
	 * @param identifier The global unique identifier of this application.
	 * @param callback The callback function that is called.
	 */
	void (*init)(char* identifier, void (*callback)(int));
	
	/**
	 * Runs the application until it is closed and blocks the current thread.
	 *
	 * @param argc The number of command line arguments.
	 * @param argv The list of the command line arguments.
	 * @return The status code of the application.
	 */
	int (*run)(int argc, char** argv);
	
	/**
	 * Prints the text to the console while the application is running.
	 *
	 * @param format A string format that can contain format tags.
	 * @param ... Additional parameters for each format tag.
	 */
	void (*print)(const char* format, ...);
	
	/**
	 * Returns an empty placeholder widget that does nothing.
	 *
	 * @return An empty, but valid placeholder widget.
	 */
	SWidget* (*placeholder)();

	/**
	 * Only used internally!
	 * Pointer to the gtk application. Should not be used externally.
	 */
	GtkApplication* app;
	
	/**
	 * Only used internally!
	 * A pointer to the widgets that are building.
	 */
	List* build_stack;
	
	/**
	 * Only used internally!
	 * Pushes a new gtk widget onto the build stack. Creates the memory
	 * dyanmically.
	 *
	 * @param type The type of the widget.
	 * @param identifier The identifier of the widget.
	 * @param gtk_widget The gtk widget that should be pushed.
	 */
	void (*push_build_stack)(SWidgetType type, char* identifier, void* gtk_widget);
	
	/**
	 * Only used internally!
	 * Pops the last widget that was pushed onto the build stack. Frees the
	 * used memory.
	 */
	void (*pop_build_stack)();
	
	/**
	 * Only used internally!
	 * Peeks at the last widget that was pushed onto the build stack.
	 *
	 * @return The widget that was peeked.
	 */
	SWidget* (*peek_build_stack)();
};
extern SGui gui;

/**
 * Initializes the special syntax for the gui functions.
 */
void gui_initialize();

