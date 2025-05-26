#pragma once
#include <SDL3/SDL.h>
#include <memory>


namespace Alcides_Util {
	//This is a custom deleter to be inserted into the unique pointer.
	struct SDL_Destroyer {
		void operator()(SDL_Window* window) const;
		void operator()(SDL_Gamepad* controller) const;
		void operator()(SDL_Cursor* cursor) const;
	};
}

typedef std::shared_ptr<SDL_Gamepad> Controller;
static Controller make_shared_controller(SDL_Gamepad* controller);

typedef std::shared_ptr<SDL_Gamepad> Cursor;
static Cursor make_shared_cursor(SDL_Cursor* cursor);

typedef std::unique_ptr<SDL_Window, Alcides_Util::SDL_Destroyer> WindowPTR;
	