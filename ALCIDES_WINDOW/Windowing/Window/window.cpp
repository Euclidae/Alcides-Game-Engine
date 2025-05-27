#include "window.hpp"
#include <iostream>

void AlcidesWindow::Window::create_new_window(uint32_t flags)
{
	m_pWindow = WindowPTR(SDL_CreateWindow(m_title.c_str(), m_width, m_height, flags));
	if (!m_pWindow) {
		std::string error = SDL_GetError();
		std::cerr << "Failed to created the window " << error << '\n';
	}
}

AlcidesWindow::Window::Window(const std::string title, int width, int height, int x_pos, int y_pos, bool v_sync, uint32_t flags):
	m_pWindow(nullptr), m_GLContext{}, m_title(title), m_width(width), m_height(height), x_pos(x_pos), y_pos(y_pos), m_window_flags(flags)
{
	create_new_window(flags);

	if (v_sync) {
		if (!SDL_SetHint(SDL_HINT_RENDER_VSYNC, "1"))
			std::cout << "Failed to enable Vsync\n";
	}
}

AlcidesWindow::Window::~Window()
{
}

void AlcidesWindow::Window::set_window_name(const std::string& name) {
	m_title = name;
	SDL_SetWindowTitle(m_pWindow.get(), name.c_str());
}
