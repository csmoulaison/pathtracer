#pragma once
#include "vector.h"

struct Camera {
	struct Vec3 position;
	float pitch;
	float yaw;
	float fov;
};

void camera_look(struct Vec2 look_direction, struct Camera* camera);
struct Vec3 camera_forward(float yaw);
