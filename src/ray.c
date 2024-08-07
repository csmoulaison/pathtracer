#include "ray.h"

struct Vec3 ray_at(struct Ray r, float t) {
    return v3_add(r.origin, v3_scale(r.direction, t));
}
