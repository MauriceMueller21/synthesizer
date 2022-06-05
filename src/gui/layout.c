#include "gui/layout.h"
#include "gui/gui.h"
#include "core/core.h"
#include <gtk/gtk.h>
#include <stdarg.h>

SLayout gui_layout_create(bool has_id, ...)
{
	SWidget* widget = malloc(sizeof(SWidget));
	widget->gtk_widget = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	widget->is_sentinal = false;
	
	if (has_id)
	{
		va_list args;
		va_start(args, has_id);
		widget->identifier = va_arg(args, char*);
		va_end(args);
	}
	
	core.list.push(gui.build_stack, widget);
	return gui.layout;
}

SWidget* gui_layout_build_callback(SWidget* widget, ...)
{
	List* children = core.list.create();
	core.list.push(children, widget->gtk_widget);
	
	va_list args;
	va_start(args, widget);
	
	for(int i = 0;;i++)
	{
		SWidget* child = va_arg(args, SWidget*);
		
		if (child->is_sentinal)
		{
			core.list.pop(gui.build_stack);
			break;
		}
		
		core.list.pop(gui.build_stack);
		core.list.push(children, child->gtk_widget);
		push_only_named_widget(gui.widgets, child);
	}
	
	va_end(args);
	
	SWidget* layout = core.list.peek(gui.build_stack);
	for (int i = 0; i < core.list.get_length(children); i++)
	{
		gtk_box_append(GTK_BOX(layout->gtk_widget), core.list.get(children, i));		
	}
	core.list.destroy(children);
	return layout;
}

SWidgetFunction gui_layout_params(char* orientation)
{
	void* layout = ((SWidget*) core.list.peek(gui.build_stack))->gtk_widget;
	gtk_orientable_set_orientation(GTK_ORIENTABLE(layout),
		(strcmp(orientation, "horizontal") == 0) ? GTK_ORIENTATION_HORIZONTAL : GTK_ORIENTATION_VERTICAL);
	return gui_layout_build_callback;
}


SWidget* SENTINAL;
SLayout Layout;
void initialize_gui_layout_syntax()
{
	Layout.create = &gui_layout_create;
	Layout.params = &gui_layout_params;
	SENTINAL = (SWidget*) malloc(sizeof(SWidget));
	SENTINAL->is_sentinal = true;
}

