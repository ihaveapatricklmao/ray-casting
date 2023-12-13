#pragma once
#ifndef RENDER_H
#define RENDER_H


#include <sdl/SDL.h>
#undef main
#include "logic.h"


using namespace glm;


namespace Render {

	struct Pixel {
		vec2 pos;
		vec4 rgba;
		unsigned int width;
	};

	struct Caster {
		std::vector<Pixel> _pixels;
		SDL_Surface* _surface;


		void assignRgba() {
			_pixels.clear();

			int w = _surface->w;
			int h = _surface->h;

			Pixel pix;

			SDL_LockSurface(_surface);
			Uint32* pixels = (Uint32*)_surface->pixels;
			Uint8 r, g, b, a;

			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x += 4) {
					for (int i = 0; i < 4; i++) {
						pix.pos = { x + i, y };
						//std::cout << pix.pos[0] << " , " << pix.pos[1] << "\n";
						SDL_GetRGBA(pixels[x + i + y * w], _surface->format, &r, &g, &b, &a);
						pix.rgba = { r, g, b, a };
						pixels[x + i + y * w] = SDL_MapRGBA(_surface->format, 200, 200, 15, 255);
						//std::cout << pix.rgba[0] << " , " << pix.rgba[1] << " , " << pix.rgba[2] << " , " << pix.rgba[3] << "\n";
						_pixels.emplace_back(pix);
					}
				}
			}

			SDL_UnlockSurface(_surface);
		}

		void scanRow() {

		}
	};

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

		int createWindow() {
			int is_sdl_init = initSdl();

			if (is_sdl_init == 0) {
				Caster raycast;
				window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
				SDL_Surface* surface = SDL_GetWindowSurface(window);
				raycast._surface = surface;
				SDL_Event window_events;
				window_events.type = SDL_WINDOWEVENT;

				SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

				while (window_events.type != SDL_QUIT) {

					if (SDL_PollEvent(&window_events)) {

						switch (window_events.type) {
							case SDL_WINDOWEVENT_RESIZED:
								SDL_SetWindowSize(window, window_events.window.data1, window_events.window.data2);
								SDL_GetWindowSize(window, &window_events.window.data1, &window_events.window.data2);
								break;
							case SDL_QUIT:
								SDL_DestroyRenderer(render);
								SDL_DestroyWindow(window);
								SDL_Quit();
								break;
						}
					}

					SDL_RenderClear(render);
					raycast.assignRgba();
					SDL_RenderPresent(render);

					SDL_UpdateWindowSurface(window);
				}
			}

			return 1;
		}

		Renderer(SDL_Window* _win, int _w, int _h) {
			w = _w;
			h = _h;
			window = _win;
		}
	};
}


#endif // !RENDER_H