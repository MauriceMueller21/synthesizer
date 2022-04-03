#include "window.h"

SWindow::SWindow()
{
	(*this)["width"] = 420;
	(*this)["height"] = 420;
	(*this)["title"] = std::string("");

	m_display = XOpenDisplay(nullptr);
	m_screen = DefaultScreen(m_display);
}

SWindow::~SWindow()
{
	XCloseDisplay(m_display);
}

void SWindow::create()
{
	int width = (*this)["width"];
	int height = (*this)["height"];
	std::string title = (*this)["title"];

	m_window = XCreateSimpleWindow(
		m_display,
		RootWindow(m_display, m_screen),
		0,
		0,
		width,
		height,
		1,
		BlackPixel(m_display, m_screen),
		WhitePixel(m_display, m_screen)
	);

	XSelectInput(m_display, m_window, ExposureMask | KeyPressMask);
	XMapWindow(m_display, m_window);
	XStoreName(m_display, m_window, title.c_str());
	XSync(m_display, false);
}

Display* SWindow::display()
{
	return m_display;
}

