#include "gui/window.h"
#include "gui/gui.h"
#include "gui/widget.h"
#include <gtk/gtk.h>

SWindow gui_window_create(char* title, int width, int height)
{
	GtkWidget *window = gtk_application_window_new (gui.app);
	gtk_window_set_title (GTK_WINDOW (window), title);
	gtk_window_set_default_size (GTK_WINDOW (window), width, height);
	gtk_widget_show (window);
	gui.push_build_stack(Window, "", window);
	return gui.window;
}

SWidget* gui_window_build_callback(SWidget* widget, ...)
{
	void* gtk_widget = widget->gtk_widget;
	gui.pop_build_stack();
	SWidget* window = gui.peek_build_stack();
	gtk_window_set_child(GTK_WINDOW(window->gtk_widget), gtk_widget);
	//gtk_window_present(GTK_WINDOW(window->gtk_widget));
	return window;
}

SWidgetFunction gui_window_build()
{
	return gui_window_build_callback;
}

SWindow window;
void gui_window_initialize()
{
	window.create = &gui_window_create;
	window.build = &gui_window_build;
}

