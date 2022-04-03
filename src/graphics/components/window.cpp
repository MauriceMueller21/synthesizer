#include "window.h"

SWindow::SWindow()
{
	m_width = 420;
	m_height = 420;
	m_title = "";

	m_display = XOpenDisplay(nullptr);
	m_screen = DefaultScreen(m_display);
}

SWindow::~SWindow()
{
	XCloseDisplay(m_display);
}

void SWindow::create()
{
	m_window = XCreateSimpleWindow(
		m_display,
		RootWindow(m_display, m_screen),
		0,
		0,
		width(),
		height(),
		1,
		BlackPixel(m_display, m_screen),
		WhitePixel(m_display, m_screen)
	);

	XSelectInput(m_display, m_window, ExposureMask | KeyPressMask);
	XMapWindow(m_display, m_window);
	XStoreName(m_display, m_window, title().c_str());
	XSync(m_display, false);
}

void SWindow::width(int width)
{
	m_width = width;
}

int SWindow::width()
{
	return m_width;
}

void SWindow::height(int height)
{
	m_height = height;
}

int SWindow::height()
{
	return m_height;
}

void SWindow::title(std::string title)
{
	m_title = title;
}

std::string SWindow::title()
{
	return m_title;
}

Display* SWindow::display()
{
	return m_display;
}

