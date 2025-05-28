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
		SDL_WindowFlags m_window_flags;
	private:
		void create_new_window(SDL_WindowFlags flags);
	public:
		Window() : Window("default", 640, 480, true, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL) {

		}

		Window(const std::string title, int width, int height, 
			bool v_sync = true, SDL_WindowFlags flags = (SDL_WINDOW_OPENGL) | (SDL_WINDOW_RESIZABLE));
		~Window();
		
		inline void set_GL_Context(SDL_GLContext& gl_context) { m_GLContext = gl_context; }
		inline SDL_GLContext& get_GL_context() { return m_GLContext; }
		inline WindowPTR& get_window() { return m_pWindow; }
		inline const std::string& get_window_name() const { return m_title; }
		void set_window_name(const std::string& name);

		[[nodiscard]]inline const int get_width() const { return m_width; }
		[[nodiscard]]inline const int get_height() const { return m_height; }

		inline const void set_width(int width) { m_width = width; }
		inline const void set_height(int height) { m_height = height; }
	};
}