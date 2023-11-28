#pragma once
#ifndef ENTITIES_H
#define ENTITIES_H

#include "include/glm/glm.hpp"
#include <cmath>


namespace Entity {

	class EntityBase {
		
		public:
			glm::vec2 pos;
			enum type {STATIC, DYNAMIC};


			void moveEntity(glm::vec2 vec_pos, double iterate) {
				float interp_x = 0.0, interp_y = 0.0;

				float delta_x, delta_y;

				delta_x = vec_pos.x - pos.x;
				delta_y = vec_pos.y - pos.y;

				float dist = (std::pow(delta_x, 2) + std::pow(delta_y, 2)) * 0.5;

				double normalized_x = delta_x / dist;
				double normalized_y = delta_y / dist;

				while (interp_x <= delta_x || interp_x >= delta_x && interp_y <= delta_y || interp_y <= delta_y ) {

					std::cout << pos.x << " " << pos.y << "\n ";
					if (interp_x <= delta_x) {
						pos.x += normalized_x;
						interp_x += iterate;
					}
					else {
						continue;
					}
					if (interp_y <= delta_y) {
						pos.y += normalized_y;
						interp_y += iterate;
					}
					else {
						continue;
					}
				}
			}
	};
}

#endif // !ENTITIES_H