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

	struct Cast {
		std::vector<vec4> rgbaVals;


		void assignRgba(SDL_Surface* _surface) {

		}

		void scanRow(SDL_Surface* _surface) {
			int w = _surface->w;
			int h = _surface->h;

			unsigned int* pixels = (unsigned int*)_surface->pixels;
			unsigned int* temp_pixels = pixels;

			if (temp_pixels != pixels) {
				for (int y = 0; y < h; y++)
				{
					for (int x = 0; x < w; x++)
					{
						if (temp_pixels[x + y * w] != pixels[x + y * w]) {
							temp_pixels[x + y * w] = pixels[x + y * w];
						}
						else {
							continue;
						}
					}
				}
			}
		}
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
				SDL_Event window_events;
				window_events.type = SDL_WINDOWEVENT;
				SDL_Surface* surface = SDL_GetWindowSurface(window);

				while (window) {

					SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

					if (SDL_PollEvent(&window_events)) {
						switch (window_events.type) {
							case SDL_WINDOWEVENT_RESIZED:
								window_events.window.data1;
								window_events.window.data2;
						}
					}
					SDL_RenderClear(render);
					SDL_RenderPresent(render);


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