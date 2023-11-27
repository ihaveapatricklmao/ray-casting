#pragma once
#ifndef RENDER_H
#define RENDER_H

#include "include/sdl/SDL.h"
#include "include/glm/glm.hpp"
#include "logic.h"

struct Ray {
	glm::vec2 origin;
	glm::vec2 end;

	void castRay() {

	}
};


namespace Render {

}

#endif // !RENDER_H