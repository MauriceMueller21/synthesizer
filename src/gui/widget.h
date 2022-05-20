#pragma once

/**
 * The types of widgets available inside the synthesizer application.
 */
typedef enum SWidgetType SWidgetType;
enum SWidgetType
{
	Window,
	Button
};

/**
 * Internal wrapper for synthesizer widgets. It is mainly a wrapper for the
 * gtk widgets. It should not be necessary to use these widgets directly.
 */
typedef struct SWidget SWidget;
struct SWidget
{
	SWidgetType type;
	char* identifier;
	void* gtk_widget;
};

/**
 * Renaming of a variadic function takes multiple widgets and returns one.
 */
typedef SWidget* (*SWidgetFunction)(SWidget*, ...);

