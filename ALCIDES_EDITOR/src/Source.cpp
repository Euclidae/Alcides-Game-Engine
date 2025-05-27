#define SDL_MAIN_HANDLED 1

#include <AlcidesUtil/SDL_Wrapper.hpp>
#include <Windowing/Window/window.hpp>
#include <iostream>
int main() {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		std::cout << "Success";
		AlcidesWindow::Window window();
		SDL_Delay(5000);
	}
	else {
		std::cerr << "SDL failed to initialize " << SDL_GetError() << std::endl;
		return -1;
	}
	return 0;
}