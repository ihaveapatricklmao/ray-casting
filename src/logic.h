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
#include "texture.hpp"


using namespace Entity;
using namespace Tex;

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

		public:
			Points pt_a, pt_b;
			enum pts {POINT_A, POINT_B};
			Textures texture;

			float wall_dist;


			float calculateWall() {
			wall_dist = std::sqrt(std::pow(pt_b.point_pos.x - pt_a.point_pos.x, 2) +
			std::pow(pt_b.point_pos.y - pt_a.point_pos.y, 2));
			}

			void wallMove(Points to_point, pts pt, bool instant, float pwr) {

				if (instant) {
					switch (pt) {
						case POINT_A: pt_a.point_pos = to_point.point_pos;
						case POINT_B: pt_b.point_pos = to_point.point_pos;
					}
				}
				else {
					switch (pt) {
						case POINT_A: 
							while (true) {

								float delta_x = to_point.point_pos.x - pt_a.point_pos.x, delta_y = to_point.point_pos.y - pt_a.point_pos.y;

								float door_dist = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));

								double normalized_delta_x = delta_x / door_dist, normalized_delta_y = delta_y / door_dist;

								pt_a.point_pos.x += (normalized_delta_x) * pwr;
								pt_a.point_pos.y += (normalized_delta_y) * pwr;

								std::cout << "Position: " << pt_a.point_pos.x << " " << pt_a.point_pos.y << "\n";
								std::cout << "Door Dist: " << door_dist << "\n";

								if (door_dist <= 0.8) {  // threshold
									std::cout << "distance reached!";
									break;
								}
							}
						case POINT_B: 
							while (true) {

								float delta_x = to_point.point_pos.x - pt_b.point_pos.x, delta_y = to_point.point_pos.y - pt_b.point_pos.y;

								float door_dist = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));

								double normalized_delta_x = delta_x / door_dist, normalized_delta_y = delta_y / door_dist;

								pt_b.point_pos.x += (normalized_delta_x) * pwr;
								pt_b.point_pos.y += (normalized_delta_y) * pwr;

								std::cout << "Position: " << pt_b.point_pos.x << " , " << pt_b.point_pos.y << "\n";
								std::cout << "Door Dist: " << door_dist << "\n";

								if (door_dist <= 0.8) {  // threshold
									std::cout << "distance reached!";
									break;
								}
							}
					}
				}
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