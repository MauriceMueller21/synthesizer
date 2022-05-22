#pragma once
#include <stdbool.h>

#define CreateWidget(type, ...)			\
	_Generic((type),					\
		SWindow: gui.window.create,		\
		SLayout: gui.layout.create,		\
		SButton: gui.button.create		\
	)(sizeof((char[]){#__VA_ARGS__}) > 1, #__VA_ARGS__)

typedef struct SWidget
{
	char* identifier;
	void* gtk_widget;
	bool is_sentinal;
} SWidget;

typedef SWidget* (*SWidgetFunction)(SWidget*, ...);

typedef struct List WidgetList;
void push_only_named_widget(WidgetList* list, SWidget* widget);

