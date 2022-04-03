#pragma once
#include <X11/Xlib.h>
#include <string>

class SWindow
{
	int m_width;
	int m_height;
	int m_screen;
	std::string m_title;
	Display* m_display;
	Window m_window;

public:
	SWindow();
	~SWindow();
	void create();

public:
	void width(int width);
	int width();
	void height(int height);
	int height();
	void title(std::string title);
	std::string title();
	Display* display();
};

