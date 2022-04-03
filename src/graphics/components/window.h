#pragma once
#include "widget.h"
#include <X11/Xlib.h>
#include <string>

class SWindow : public SWidget
{
	int m_screen;
	Display* m_display;
	Window m_window;

public:
	SWindow();
	~SWindow();
	void create();

public:
	Display* display();
};

