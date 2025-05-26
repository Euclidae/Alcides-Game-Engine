#include "SDL_Wrapper.hpp"
#include <iostream>

namespace Alcides_Util {
	void SDL_Destroyer::operator()(SDL_Window* window) const
	{
		SDL_DestroyWindow(window);
	}

	void SDL_Destroyer::operator()(SDL_Gamepad* controller) const
	{

	}

	void SDL_Destroyer::operator()(SDL_Cursor* cursor) const
	{

	}
}
	

Controller make_shared_controller(SDL_Gamepad* controller)
{
	return Controller();
}

Cursor make_shared_cursor(SDL_Cursor* cursor)
{
	return Cursor();
}
