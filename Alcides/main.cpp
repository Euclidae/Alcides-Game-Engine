#define SDL_MAIN_HANDLED
#include <AlcidesUtil/SDL_Wrapper.hpp>
#include <Windowing/Window/window.hpp>
#include <iostream>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) { // Check for success (0)
        std::cout << "SDL initialized successfully\n";
        AlcidesWindow::Window window("Alcides Engine", 1920, 1080, true, SDL_WINDOW_RESIZABLE); // Fix: Remove parentheses
        SDL_Delay(5000);
    }
    else {
        // Clean up SDL before exiting  
        std::cerr << "SDL failed to initialize: " << SDL_GetError() << std::endl;
        return -1;
    }


    return 0;
}