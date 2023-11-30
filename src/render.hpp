#pragma once
#ifndef RENDER_H
#define RENDER_H


#include <sdl/SDL_main.h>
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


#endif // !RENDER_H