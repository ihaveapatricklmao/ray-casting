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
		std::vector<Pixel> _pixels;
		SDL_Surface* _surface;


		void assignRgba() {
			_pixels.clear();

			int w = _surface->w;
			int h = _surface->h;

			Pixel pix;
			Uint32* pixels = (Uint32*)_surface->pixels;

			for (int y = 0; y < h; y++)
			{
				for (int x = 0; x < w; x++)
				{
					Uint8 r, g, b, a;
					pix.pos = { x, y };
					SDL_GetRGBA(pixels[x + y * w], _surface->format, &r, &g, &b, &a);
					pix.rgba = { r, g, b, a };
					_pixels.emplace_back(pix);
					std::cout << pix.rgba[0] << " , " << pix.rgba[1] << " , " << pix.rgba[2] << " , " << pix.rgba[3] << "\n";
				}
			}
		}

		void scanRow() {

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