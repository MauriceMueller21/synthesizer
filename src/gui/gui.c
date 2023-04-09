#include "gui/gui.h"
#include "core/core.h"
#include <gtk/gtk.h>
#include <stdio.h>
#include <stdarg.h>

void gtk_callback(GtkApplication*, gpointer callback)
{
	((void (*)()) callback)();
}

void gui_init(char* identifier, void (*callback)(int))
{
	gui.app = gtk_application_new(identifier, G_APPLICATION_DEFAULT_FLAGS);
	g_signal_connect(gui.app, "activate", G_CALLBACK(gtk_callback), callback);
	gui.widgets = core.list.create();
	gui.build_stack = core.list.create();
}

int gui_run(int argc, char** argv)
{
	int status = g_application_run(G_APPLICATION(gui.app), argc, argv);
	g_object_unref(gui.app);
	core.list.destroy(gui.widgets);
	core.list.destroy(gui.build_stack);
	return status;
}

void gui_print(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	char* string;
	if (vasprintf(&string, format, args) > 0)
	{
		g_print(string);
	}
	va_end(args);
}

struct GuiFunctions gui;
void initialize_gui_syntax()
{
	gui.init = &gui_init;
	gui.run = &gui_run;
	gui.print = &gui_print;
	
	initialize_gui_window_syntax();
	gui.window = Window;
	initialize_gui_layout_syntax();
	gui.layout = Layout;
	initialize_gui_button_syntax();
	gui.button = Button;
	//initialize_gui_console_syntax();
	//gui.console = Console;
}

