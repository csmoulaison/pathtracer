#pragma once
#include "vector.h"

struct Intersection {
	int intersected;
	float t;
	struct Vec3 point;
    struct Vec3 normal;
};
