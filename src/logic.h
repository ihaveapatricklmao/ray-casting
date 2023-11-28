#pragma once
#ifndef LOGIC_H
#define LOGIC_H


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include "include/glm/glm.hpp"
#include "include/camera.h"
#include "include/entities.h"


namespace World {

	struct Points {
		glm::vec2 point_pos;
	};

	class Wall {
		Points pt_a;
		Points pt_b;

		int wallDist;


		int calculateWall() {
			wallDist = std::sqrt(std::pow(pt_b.point_pos.x - pt_a.point_pos.x, 2) + 
				std::pow(pt_b.point_pos.y - pt_a.point_pos.y, 2));
		}
	};

	class Grid {
		Points pt_a;
		Points pt_b;
		Points pt_c;
		Points pt_d;
	};

	struct Space {

		std::vector<Grid> _grids;
		std::vector<Wall> _walls;

		void assignWorld(Grid* grids, Wall* walls) {

			for (int i = 0; i < sizeof(grids) / sizeof(Grid); i++ ) {
				_grids.push_back(grids[i]);
			}
			for (int x = 0; x < sizeof(walls) / sizeof(Wall); x++) {
				_walls.push_back(walls[x]);
			}
		}

		int evalSizeGrids() {
			return _grids.size();
		}

		int evalSizeWalls() {
			return _walls.size();
		}
	};
}

#endif // !LOGIC_H