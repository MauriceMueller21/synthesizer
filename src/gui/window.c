#include "gui/window.h"
#include "gui/gui.h"
#include "core/core.h"
#include <gtk/gtk.h>
#include <stdarg.h>

SWindow gui_window_create(bool has_id, ...)
{
	SWidget* widget = malloc(sizeof(SWidget));
	widget->gtk_widget = gtk_application_window_new(gui.app);
	widget->is_sentinal = false;
	
	if (has_id)
	{
		va_list args;
		va_start(args, has_id);
		widget->identifier = va_arg(args, char*);
		va_end(args);
	}
	
	core.list.push(gui.build_stack, widget);
	return gui.window;
}

SWidget* gui_window_build_callback(SWidget* widget, ...)
{
	core.list.pop(gui.build_stack);
	SWidget* window = core.list.peek(gui.build_stack);
	core.list.pop(gui.build_stack);
	gtk_window_set_child(GTK_WINDOW(window->gtk_widget), widget->gtk_widget);
	push_only_named_widget(gui.widgets, widget);
	push_only_named_widget(gui.widgets, window);
	return 0;
}

SWidgetFunction gui_window_params(char* title, int width, int height)
{
	void* window = ((SWidget*) core.list.peek(gui.build_stack))->gtk_widget;
	gtk_window_set_title(GTK_WINDOW(window), title);
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	gtk_window_present(window);
	return gui_window_build_callback;
}

SWindow Window;
void initialize_gui_window_syntax()
{
	Window.create = &gui_window_create;
	Window.params = &gui_window_params;
}

