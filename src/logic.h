#pragma once
#ifndef LOGIC_HPP
#define LOGIC_HPP


#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include "include/glm/glm.hpp"
#include "camera.h"
#include "entities.h"

using namespace Entity;

namespace World {

	struct Points {
		glm::vec2 point_pos;

		Points(float vec_x, float vec_y) {
			point_pos.x = vec_x;
			point_pos.y = vec_y;
		}

		Points() = default;
	};

	class Wall {
		Points pt_a, pt_b;


		float wallDist;

		float calculateWall() {
			wallDist = std::sqrt(std::pow(pt_b.point_pos.x - pt_a.point_pos.x, 2) +
			std::pow(pt_b.point_pos.y - pt_a.point_pos.y, 2));
		}

		Wall(Points a, Points b) {
			pt_a = a;
			pt_b = b;
		}

		Wall() = default;
	};

	 
	struct Space {

		std::vector<Wall> _walls;
		std::vector<EntityBase> _entities;
		glm::vec3 ceiling_color;
		glm::vec3 floor_color;


		void assignWorld(Wall* walls, EntityBase* entities) {

			for (int x = 0; x < sizeof(walls) / sizeof(Wall); x++) {
				_walls.push_back(walls[x]);
			}
			for (int z = 0; z < sizeof(entities) / sizeof(EntityBase); z++) {
				_entities.push_back(entities[z]);
			}
		}


		int evalSizeWalls() {
			return _walls.size();
		}

		int evalEntitySize() {
			return _entities.size();
		}

		Space(glm::vec3 color_floor, glm::vec3 color_ceil) {
			ceiling_color = color_ceil;
			floor_color = color_floor;
		}

		Space() = default;
	};
}

#endif // !LOGIC_H