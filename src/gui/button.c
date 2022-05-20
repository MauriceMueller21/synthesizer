#include "gui/button.h"
#include "gui/gui.h"
#include <gtk/gtk.h>
SButton button;

SButton gui_button_create(char* label, void (*callback)())
{
	GtkWidget *button = gtk_button_new_with_label(label);
	g_signal_connect(button, "clicked", G_CALLBACK(callback), NULL);
	gui.push_build_stack(Button, "", button);
	return gui.button;
}

SWidget* gui_button_build()
{
	return gui.peek_build_stack();
}

void gui_button_initialize()
{
	button.create = &gui_button_create;
	button.build = &gui_button_build;
}

