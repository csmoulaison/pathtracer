#pragma once
#include "vector.h"

struct Camera {
	struct Vec3 position;
	struct Vec2 orientation;
	float fov;
};

void camera_look(struct Vec2 look_direction, struct Camera* camera);
