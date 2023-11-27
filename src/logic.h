#pragma once
#ifndef LOGIC_H
#define LOGIC_H


#include <iostream>
#include <stdio.h>
#include <vector>
#include "include/glm/glm.hpp"
#include "include/camera.h"
#include "include/entities.h"
#include "include/walls.h"


namespace World {

	struct points {
		glm::vec2 point_pos;
	};

	class grid {
		points pt_a;
		points pt_b;
		points pt_c;
		points pt_d;
	};

	struct space {
		std::vector<grid> _grids;
	};
}

#endif // !LOGIC_H