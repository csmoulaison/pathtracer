#pragma once
#include "ray.h"
#include "intersection.h"
#include "min.h"
#include "sphere.h"

void render(struct Sphere* spheres, uint8_t spheres_len, uint32_t width, uint32_t height, uint32_t* out_pixels);
struct Intersection intersect_world(struct Ray ray, struct Sphere* spheres, uint8_t spheres_len);
struct Intersection intersect_sphere(struct Ray r, struct Sphere s);
uint32_t sky_color(struct Ray r);
