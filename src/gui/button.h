#pragma once
#include "gui/widget.h"
#include <stdbool.h>

typedef struct SButton SButton;
struct SButton
{
	SButton (*create)(bool has_id, ...);
	SWidget* (*params)(char* label, void(*callback)());
};
extern SButton Button;

void initialize_gui_button_syntax();

