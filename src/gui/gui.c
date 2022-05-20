#include "gui/gui.h"
#include "core/core.h"
#include <stdio.h>
#include <stdarg.h>

void gtk_callback(GtkApplication*, gpointer callback)
{
	((void (*)()) callback)();
}

void gui_init(char* identifier, void (*callback)(int))
{
	gui.app = gtk_application_new(identifier, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(gui.app, "activate", G_CALLBACK(gtk_callback), callback);
	gui.build_stack = core.list.create();
}

int gui_run(int argc, char** argv)
{
	int status = g_application_run(G_APPLICATION(gui.app), argc, argv);
	core.list.destroy(gui.build_stack);
	g_object_unref(gui.app);
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

SWidget* gui_placeholder()
{
	gui.push_build_stack(Window, "", 0);
	return gui.peek_build_stack();
}

void gui_push_build_stack(SWidgetType type, char* identifier, void* gtk_widget)
{
	SWidget* widget = (SWidget*) malloc(sizeof(SWidget));
	widget->type = type;
	widget->identifier = identifier;
	widget->gtk_widget = gtk_widget;
	core.list.add(gui.build_stack, widget);
}

void gui_pop_build_stack()
{
	int length = core.list.get_length(gui.build_stack);
	void* item = core.list.get(gui.build_stack, length - 1);
	core.list.remove(gui.build_stack, length - 1);
	free(item);
}

SWidget* gui_peek_build_stack()
{
	int length = core.list.get_length(gui.build_stack);
	void* item = core.list.get(gui.build_stack, length - 1);
	SWidget* widget = (SWidget*) item;
	return widget;
}

SGui gui;
void gui_initialize()
{
	gui_window_initialize();
	gui.window = window;
	gui_button_initialize();
	gui.button = button;
	gui.init = &gui_init;
	gui.run = &gui_run;
	gui.print = &gui_print;
	gui.placeholder = &gui_placeholder;
	gui.push_build_stack = &gui_push_build_stack;
	gui.pop_build_stack = &gui_pop_build_stack;
	gui.peek_build_stack = &gui_peek_build_stack;
}

