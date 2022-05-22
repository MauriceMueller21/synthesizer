#pragma once
#include "gui/widget.h"
#include <stdbool.h>

typedef struct SLayout SLayout;
struct SLayout
{
	SLayout (*create)(bool has_id, ...);
	SWidgetFunction (*params)(char* orientation);
};
extern SLayout Layout;
extern SWidget* SENTINAL;

void initialize_gui_layout_syntax();

