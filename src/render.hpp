#pragma once
#ifndef RENDER_H
#define RENDER_H


#include <sdl/SDL.h>
#undef main
#include "logic.h"


using namespace glm;
using namespace World;

namespace Render {

	struct Pixel {
		vec2 pos;
		vec4 rgba;
	};

	struct Line {
		Points origin_pt;
		vec2 vec_dir;
		Points end_pt;
		double angle;

		void createLine (vec2 _ori, vec2 _dir, Camera _cam) {
			origin_pt.point_pos = _ori;

			vec_dir = _dir;
		}

	};

	struct Caster {
		std::vector<Pixel> _pixels;
		std::vector<Line> _lines;
		SDL_Surface* _surface;


		void assignRgba() {
			_pixels.clear();

			int w = _surface->w;
			int h = _surface->h;


			Pixel* pix = new Pixel;

			SDL_LockSurface(_surface);
			Uint32* pixels = (Uint32*)_surface->pixels;
			Uint8 r, g, b, a;

			for (int y = 0; y < h; y++) {
				for (int x = 0; x < w; x++) {
					pixels[x + y * w] = SDL_MapRGBA(_surface->format, 0, 170, 95, 255);
					pix->pos = { x, y };
					SDL_GetRGBA(pixels[x + y * w], _surface->format, &r, &g, &b, &a);
					pix->rgba = { r, g, b, a };
					_pixels.emplace_back(*pix);
				}
			}

			delete pix;

			SDL_UnlockSurface(_surface);
		}

		void clearPixelBuffer() {
			_pixels.clear();
		}

		void scan(Camera* _cam) {

			_cam->calculatePlane(32.0, 32.0);

			std::cout << _cam->plane_dir << "\n";

			std::cout << _cam->dir.x << "\n";
			std::cout << _cam->dir.y << "\n";

			Line* _line_a = new Line;
			Line* _line_b = new Line;

			for (int i = 0; i >= _cam->plane_pt_a.x; i--) {
				for (int z = 0; i <= _cam->plane_pt_b.x; z++) {
					_line_a->createLine(_cam->pos, { (_cam->dir.x - _cam->plane_dir * 1 / i) - 0.00001, (_cam->dir.y - _cam->plane_dir * 1 / i) - 0.00001 }, *_cam);
					_line_b->createLine(_cam->pos, { (_cam->dir.x + _cam->plane_dir * 1 / z) + 0.00001, (_cam->dir.y + _cam->plane_dir * 1 / z) + 0.00001 } , *_cam);



					_lines.emplace_back(*_line_a);
					_lines.emplace_back(*_line_b);
				}
			}

			delete _line_a;
			delete _line_b;
		}

		void clearScanBuffer() {
			_lines.clear();
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
			SDL_SetMainReady();

			int is_sdl_init = initSdl();

			if (is_sdl_init == 0) {
				Caster raycast;
				window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, SDL_WINDOW_RESIZABLE);
				SDL_Surface* surface = SDL_GetWindowSurface(window);
				raycast._surface = surface;
				SDL_Event* window_events = new SDL_Event;
				window_events->type = SDL_WINDOWEVENT;

				SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

				Camera new_cam{};
				new_cam.pos = { 20, 2 };

				raycast.scan(&new_cam);


				while (window_events->type != SDL_QUIT) {

					if (SDL_PollEvent(window_events)) {

						switch (window_events->window.event) {
							case SDL_WINDOWEVENT_RESIZED:
								SDL_SetWindowSize(window, window_events->window.data1, window_events->window.data2);
								SDL_GetWindowSize(window, &window_events->window.data1, &window_events->window.data2);

								//SDL_Log("Window %d resized to %dx%d", window_events->window.windowID, window_events->window.data1, window_events->window.data2);

								//std::cout << (int)raycast._surface->w << "\n";
								//std::cout << (int)raycast._surface->h << "\n";

								SDL_FreeSurface(raycast._surface);
								raycast._surface = SDL_GetWindowSurface(window);

								raycast.assignRgba();
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