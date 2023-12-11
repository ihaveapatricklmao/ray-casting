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
		vec4 rgba;
		unsigned int width;
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

		void createWindow() {
			int is_sdl_init = initSdl();

			if (is_sdl_init == 0) {
				window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
				SDL_Surface* surface = SDL_GetWindowSurface(window);

				while (window) {
					unsigned int* pixel = (unsigned int*)surface->pixels;
					SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

					for (int y = 0; y < h; ++y)
					{
						for (int x = 0; x < w; ++x)
						{
							pixel[x + y * w] =
								SDL_MapRGBA(surface->format, 200, 100, 250, 255);
						}
					}


					SDL_UpdateWindowSurface(window);
				}
			}
		}

		Renderer(SDL_Window* _win, int _w, int _h) {
			w = _w;
			h = _h;
			window = _win;
		}
	};
}


#endif // !RENDER_H