#include "window.hpp"
#include <iostream>

void AlcidesWindow::Window::create_new_window(SDL_WindowFlags flags)
{
	const char* title = m_title.c_str();

	m_pWindow = WindowPTR(SDL_CreateWindow(title,m_width, m_height,flags));
	if (!m_pWindow) {
		std::string error = SDL_GetError();
		std::cerr << "Failed to create the window : " << error << '\n';
	}
}

AlcidesWindow::Window::Window(const std::string title, int width, int height, bool v_sync, SDL_WindowFlags flags):
	m_pWindow(nullptr), m_GLContext{}, m_title(title), m_width(width), m_height(height),m_window_flags(flags)
{
	create_new_window(flags);
	
	/*if (v_sync) {
		if (!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"))
			std::cerr << "Failed to enable Vsync\n";
	}*/
}

AlcidesWindow::Window::~Window()
{
}

void AlcidesWindow::Window::set_window_name(const std::string& name) {
	m_title = name;
	SDL_SetWindowTitle(m_pWindow.get(), name.c_str());
}
