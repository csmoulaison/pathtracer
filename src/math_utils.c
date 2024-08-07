#include "math_utils.h"

#define _USE_MATH_DEFINES
#include <math.h>

float degrees_to_radians(float d) {
	return d * M_PI / 180.0;
}

/*
struct Vec3 rotate_vector(struct Quaternion q, struct Vec3 v) {
	struct Vec3 qv = { q.x, q.y, q.z };
	struct Vec3 uv = v3_cross(qv, v);
	struct Vec3 uuv = v3_cross(qv, uv);
	uv = v3_scale(uv, 2.0 * q.w);
	uuv = v3_scale(uuv, 2.0);
	return v3_add(v3_add(v, uv), uuv);
}
*/


