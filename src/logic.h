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

	struct Points {
		glm::vec2 point_pos;
	};

	class Grid {
		Points pt_a;
		Points pt_b;
		Points pt_c;
		Points pt_d;
	};

	struct Space {

		std::vector<Grid> _grids;

		void assignGrids(Grid* grids) {

			for (int i = 0; i < sizeof(grids) / sizeof(Grid) ; i++ ) {
				_grids.push_back(grids[i]);
			}

		}

		int evalSize() {
			return _grids.size();
		}
	};
}

#endif // !LOGIC_H