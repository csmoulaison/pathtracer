#pragma once
#include "vector.h"
#include "sphere.h"
#include "camera.h"
#include "box.h"

#define SPHERES_MAX 8
#define BOXES_MAX 8

struct World {
	struct Camera camera;
	struct Sphere spheres[SPHERES_MAX];
	uint8_t spheres_len;
    struct Box boxes[BOXES_MAX];
    uint8_t boxes_len;
};

