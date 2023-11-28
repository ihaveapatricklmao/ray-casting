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


			void moveEntity(glm::vec2 vec_pos, float pwr) {

				while (true) {

					float delta_x = vec_pos.x - pos.x, delta_y = vec_pos.y - pos.y;

					float dist = std::sqrt(std::pow(delta_x, 2) + std::pow(delta_y, 2));

					double normalized_delta_x = delta_x / dist, normalized_delta_y = delta_y / dist;

					pos.x += normalized_delta_x;
					pos.y += normalized_delta_y;

					//std::cout << pos.x << " " << pos.y << "\n";
					//std::cout << dist << "\n";

					if (dist <= 0.1) {  // Adjust the threshold as needed
						std::cout << "Entity reached the target position.\n";
						break;
					}
				}
			}
	};
}

#endif // !ENTITIES_H