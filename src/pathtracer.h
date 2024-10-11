#pragma once
#include "ray.h"
#include "intersection.h"
#include "min.h"
#include "sphere.h"
#include "box.h"

void render(struct Vec3 origin, struct Vec3 lookat, struct Box* boxes, uint8_t boxes_len, uint32_t width, uint32_t height, uint32_t* out_pixels);
struct Intersection intersect_world(struct Ray ray, struct Box* boxes, uint8_t boxes_len);
struct Intersection intersect_box(struct Ray r, struct Vec3 inv_ray_dir, struct Box b);
struct Intersection intersect_sphere(struct Ray r, struct Sphere s);
uint32_t sky_color(struct Ray r);
