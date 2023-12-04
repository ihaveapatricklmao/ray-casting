#pragma once
#ifndef RENDER_H
#define RENDER_H


#include <sdl/SDL.h>
#undef main
#include "logic.h"


using namespace glm;


namespace RenderingTools {

	struct Pixel {
		vec2 pos;
		vec3 color;
	};

	struct Ray {
		vec2 origin;
		vec2 end;
	};

}

namespace Render {

	struct Renderer {
		int w;
		int h;

		SDL_Window* window;


		int initSdl() {
			if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
				return 0;
			}
			else {
				std::cout << "error init sdl! : " << SDL_GetError() << std::endl;
				SDL_Quit();
				return -1;
			}
		}

		void createWindow(SDL_Window* _window) {
			int is_sdl_init = initSdl();

			if (is_sdl_init == 0) {
				SDL_Surface* surface = SDL_GetWindowSurface(_window);
				while (_window) {
					SDL_Renderer* render = SDL_CreateRenderer(_window, -1, 0);
				}
			}
		}

		Renderer(SDL_Window* _win) {
			window = _win;
		}
	};
}


#endif // !RENDER_H