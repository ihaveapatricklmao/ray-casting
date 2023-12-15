#pragma once
#ifndef CAMERA_H
#define CAMERA_H


#include "entities.h"


class Camera : public Entity::EntityBase {
	public:
		vec2 dir;
		vec2 plane_pt_a;
		vec2 plane_pt_b;
		double plane_dir;


		void calculatePlane(double _dir, double _plane) {
			dir.x = this->pos.x + _dir;
			dir.y = this->pos.y + _dir;

			plane_pt_a.x = dir.x - _plane;
			plane_pt_a.y = dir.y - _plane;

			plane_pt_b.x = dir.x + _plane;
			plane_pt_b.y = dir.y + _plane;

			plane_dir = std::sqrt(std::pow(plane_pt_b.x - plane_pt_a.x, 2) + std::pow(plane_pt_b.y - plane_pt_a.y, 2));

		}

};

#endif // !CAMERA_H