#pragma once
#include "vector.h"
#include "sphere.h"
#include "camera.h"

struct World {
	struct Camera camera;
	struct Sphere sphere;
	struct Sphere floor;
};
