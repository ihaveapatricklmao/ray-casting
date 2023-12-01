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

	void createWindow(int width, int height) {
		int is_sdl_init = initSdl();

		if (is_sdl_init == 0) {
			SDL_Window* window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

			SDL_Renderer* render = SDL_CreateRenderer(window, -1, 0);

			SDL_Delay(3000);
		}
	}
}


#endif // !RENDER_H