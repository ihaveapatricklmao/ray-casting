#include "src/render.hpp"


using namespace World;
using namespace Entity;
using namespace Render;


int main() {
	
	SDL_Window* new_window = nullptr;
	Renderer new_render(new_window, 600, 600);
	new_render.createWindow();

	// stuff can be done under here for when the game is closed
	std::cout << "quitted!";

	return -1;
}