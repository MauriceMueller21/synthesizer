#include "gui/layout.h"
#include "gui/gui.h"
#include "core/core.h"
#include "core/list.h"
#include <gtk/gtk.h>
#include <stdarg.h>
SLayout layout;

SLayout gui_layout_create(char* type)
{
	GtkOrientation orientation = (strcmp(type, "horizontal") == 0) ? GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL;
	GtkWidget* layout = gtk_box_new(orientation, 0);
	gui.push_build_stack(Layout, "", layout);
	return gui.layout;
}

SWidget* gui_layout_build_callback(SWidget* widget, ...)
{
	List* list = core.list.create();
	core.list.add(list, widget->gtk_widget);
	gui.pop_build_stack();

	va_list args;
	va_start(args, widget);
	
	for(int i = 0;;i++)
	{
		widget = va_arg(args, SWidget*);
	
		if (widget->type == Stopper)
		{
			gui.pop_build_stack();
			break;
		}
		
		core.list.add(list, widget->gtk_widget);
		gui.pop_build_stack();
	}
	
	va_end(args);

	SWidget* layout = gui.peek_build_stack();
	for (int i = 0; i < core.list.get_length(list); i++)
	{
		gtk_box_append(GTK_BOX(layout->gtk_widget), core.list.get(list, i));		
	}
	
	core.list.destroy(list);
	return layout;
}

SWidgetFunction gui_layout_build()
{
	return gui_layout_build_callback;
}

void gui_layout_initialize()
{
	layout.create = &gui_layout_create;
	layout.build = &gui_layout_build;
}

