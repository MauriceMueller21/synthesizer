#include "gui/button.h"
#include "gui/gui.h"
#include "core/core.h"
#include "core/extensions.h"
#include <gtk/gtk.h>

SButton gui_button_create(bool has_id, ...)
{
	SWidget* widget = malloc(sizeof(SWidget));
	widget->gtk_widget = gtk_button_new_with_label("");
	widget->is_sentinal = false;
	
	if (has_id)
	{
		va_list args;
		va_start(args, has_id);
		widget->identifier = va_arg(args, char*);
		va_end(args);
	}
	
	core_list_push(gui.build_stack, widget);
	return gui.button;
}

SWidget* gui_button_params(char* label, void(*callback)())
{
	SWidget* button = (SWidget*) core_list_peek(gui.build_stack);
	gtk_button_set_label(GTK_BUTTON(button->gtk_widget), label);
	g_signal_connect(button->gtk_widget, "clicked", G_CALLBACK(callback), NULL);	
	return button;
}

SButton Button;
void initialize_gui_button_syntax()
{
	Button.create = &gui_button_create;
	Button.params = &gui_button_params;
}

