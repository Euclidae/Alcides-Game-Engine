#pragma once
#include <AlcidesUtil/SDL_Wrapper.hpp>
#include <string>
namespace AlcidesWindow {
	class Window {
	private:
		WindowPTR m_pWindow;
		SDL_GLContext m_GLContext;
		std::string m_title;
		int m_width, m_height;
		int x_pos, y_pos;
		uint32_t m_window_flags;
	private:
		void create_new_window(uint32_t flags);
	public:
		Window() : Window("default", 640, 480, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, true, NULL) {

		}

		Window(const std::string title, int width, int height, int x_pos, int y_pos,
			bool v_sync = true, uint32_t flags = (SDL_WINDOW_OPENGL) | (SDL_WINDOW_RESIZABLE));
		~Window();

		inline void set_GL_Context(SDL_GLContext& gl_context) { m_GLContext = gl_context; }
		inline SDL_GLContext& get_GL_context() { return m_GLContext; }
		inline WindowPTR& get_window() { return m_pWindow; }
		inline const std::string& get_window_name() const { return m_title; }
		void set_window_name(const std::string& name);

		inline const int get_x_pos() const { return x_pos; }
		inline const int get_y_pos() const { return y_pos; }

		inline const void set_x_pos(int new_x_pos) { x_pos = new_x_pos; }
		inline const void set_y_pos(int new_y_pos) { y_pos = new_y_pos; }

		inline const int get_width() const { return m_width; }
		inline const int get_height() const { return m_height; }

		inline const void set_width(int width) { m_width = width; }
		inline const void set_height(int height) { m_height = height; }
	};
}