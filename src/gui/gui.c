#include "gui.h"

GuiFunctions gui;

void gtk_callback(GtkApplication*, gpointer callback)
{
	((void (*)()) callback)();
}

void gui_init(char* identifier, void (*callback)(int))
{
	gui.app = gtk_application_new(identifier, G_APPLICATION_FLAGS_NONE);
	g_signal_connect(gui.app, "activate", G_CALLBACK(gtk_callback), callback);
}

void gui_create(char* title, int width, int height)
{
	GtkWidget *window = gtk_application_window_new (gui.app);
	gtk_window_set_title (GTK_WINDOW (window), title);
	gtk_window_set_default_size (GTK_WINDOW (window), width, height);
	gtk_widget_show (window);
}

int gui_run(int argc, char** argv)
{
	int status = g_application_run(G_APPLICATION(gui.app), argc, argv);
	g_object_unref(gui.app);
	return status;
}

void gui_initialize()
{
	gui.init = &gui_init;
	gui.create = &gui_create;
	gui.run = &gui_run;
}
