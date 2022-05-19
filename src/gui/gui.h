#pragma once
#include <gtk/gtk.h>

typedef struct GuiFunctions
{
	/**
	 * Pointer to the gtk application. Should not be used externally.
	 */
	GtkApplication *app;
	
	/**
	 * Initializes the gtk application and runs the given callback function once
	 * the application starts.
	 *
	 * @param identifier The global unique identifier of this application.
	 * @param callback The callback function that is called.
	 */
	void (*init)(char* identifier, void (*callback)(int));
	
	/**
	 * Creates a new window inside the application with the given properties.
	 *
	 * @param title The displayed title of the window.
	 * @param width The initial width of the window.
	 * @param height The initial height of the window.
	 */
	void (*create)(char* title, int width, int height);
	
	/**
	 * Runs the application until it is closed and blocks the current thread.
	 *
	 * @param argc The number of command line arguments.
	 * @param argv The list of the command line arguments.
	 * @return The status code of the application.
	 */
	int (*run)(int argc, char** argv);
}
GuiFunctions;
extern GuiFunctions gui;
void gui_initialize();

