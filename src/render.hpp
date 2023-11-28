#pragma once
#ifndef RENDER_H
#define RENDER_H

#include <sdl/SDL_main.h>
#undef main
#include "logic.h"

struct Ray {
	glm::vec2 origin;
	glm::vec2 end;
};


#endif // !RENDER_H