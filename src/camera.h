#pragma once
#ifndef CAMERA_H
#define CAMERA_H


#include "entities.h"


class Camera : public Entity::EntityBase {
	public:
		int fov;
		double angle;

};

#endif // !CAMERA_H