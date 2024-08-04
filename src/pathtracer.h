#pragma once
#include "world.h"

void render(struct World* world, uint32_t width, uint32_t height, uint32_t* out_pixels);
struct Intersection intersect_world(struct Ray* ray, struct World* world);
struct Intersection intersect_sphere(struct Ray* r, struct Sphere s);
uint32_t sky_color(struct Ray r);
