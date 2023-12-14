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
using namespace glm;


namespace World {

	struct Points {
		vec2 point_pos;

		Points(float vec_x, float vec_y) {
			point_pos.x = vec_x;
			point_pos.y = vec_y;
		}

		Points() = default;
	};

	class Wall {

		public:
			int width;
			int height;
			Points pt_a, pt_b;
			enum pts {POINT_A, POINT_B};
			Textures texture;
			vec4 rgba;

			float wall_dist;


			void wallMove(Points to_point, pts pt, bool instant, float pwr) {

				if (instant) {
					switch (pt) {
						case POINT_A: 
							pt_a.point_pos = to_point.point_pos;
							std::cout << pt_a.point_pos.x << " , " << pt_a.point_pos.y << "\n";
						case POINT_B: 
							pt_b.point_pos = to_point.point_pos;
							std::cout << pt_b.point_pos.x << " , " << pt_b.point_pos.y << "\n";
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

								std::cout << "Position: " << pt_a.point_pos.x << " , " << pt_a.point_pos.y << "\n";
								std::cout << "Door Dist: " << door_dist << "\n";

								if (door_dist <= 0.8) {  // threshold
									std::cout << "distance reached!\n";
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
									std::cout << "distance reached!\n";
									break;
								}
							}
					}
				}
			}

		Wall(int w, int h, Points pt_1, Points pt_2, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
			width = w;
			height = h;
			pt_a = pt_1;
			pt_b = pt_2;
			rgba = { r, g, b, a };

			wall_dist = std::sqrt(std::pow(pt_b.point_pos.x - pt_a.point_pos.x, 2) +
						std::pow(pt_b.point_pos.y - pt_a.point_pos.y, 2));
		}

		Wall() = default;
	};

	 
	struct Space {

		std::vector<Wall> _walls;
		std::vector<EntityBase> _entities;
		vec3 ceiling_color;
		vec3 floor_color;


		void assignWorld(std::vector<Wall> walls, std::vector<EntityBase> entities) {

			for (int x = 0; x < walls.size(); x++) {
				//std::cout << "iterate walls\n";
				_walls.push_back(walls[x]);
			}
			for (int z = 0; z < entities.size(); z++) {
				//std::cout << "iterate entities\n";
				_entities.push_back(entities[z]);
			}
		}


		int evalSizeWalls() {
			return _walls.size();
		}

		int evalEntitySize() {
			return _entities.size();
		}

		Space(vec3 color_floor, vec3 color_ceil) {
			ceiling_color = color_ceil;
			floor_color = color_floor;
		}

		Space() = default;
	};
}

#endif // !LOGIC_H