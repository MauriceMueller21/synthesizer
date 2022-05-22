#pragma once
#include "gui/widget.h"
#include <stdbool.h>

typedef struct SWindow SWindow;
struct SWindow
{
	SWindow (*create)(bool has_id, ...);
	SWidgetFunction (*params)(char* title, int width, int height);
};
extern SWindow Window;

void initialize_gui_window_syntax();

