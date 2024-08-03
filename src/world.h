#pragma once
#include "math_utils.h"

struct Camera {
	struct Vec3 position;
	struct Vec2 orientation;
	float fov;
};

struct World {
	struct Camera camera;
	struct Sphere sphere;
	struct Sphere floor;
};

void camera_look(struct Vec2 look_direction, struct Camera* camera);
