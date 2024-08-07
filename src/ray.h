#pragma once
#include "vector.h"

struct Ray {
	struct Vec3 origin;
	struct Vec3 direction; // normalized
};

struct Vec3 ray_at(struct Ray r, float t);
