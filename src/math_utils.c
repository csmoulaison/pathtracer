#include "math_utils.h"

#define _USE_MATH_DEFINES
#include <math.h>

struct Vec3 v3_zero() {
    return (struct Vec3){0, 0, 0};
}

struct Vec3 v3_normalize(struct Vec3 v) {
    float length = v3_length(v);
	if (length > 0) {
		float inverse = 1 / length;
		return (struct Vec3) { v.x * inverse, v.y * inverse, v.z * inverse };
	}

	return v;
}

struct Vec3 v3_unit(struct Vec3 v) {
    return v3_div(v, v3_length(v));
}

struct Vec3 v3_add(struct Vec3 a, struct Vec3 b) {
	return (struct Vec3) { a.x + b.x, a.y + b.y, a.z + b.z };
}

struct Vec3 v3_sub(struct Vec3 a, struct Vec3 b) {
	return (struct Vec3) { a.x - b.x, a.y - b.y, a.z - b.z };
}

struct Vec3 v3_mult(struct Vec3 a, struct Vec3 b) {
	return (struct Vec3) { a.x * b.x, a.y * b.y, a.z * b.z };
}

struct Vec3 v3_scale(struct Vec3 v, float s) {
	return (struct Vec3) { v.x * s, v.y * s, v.z * s };
}

struct Vec3 v3_div(struct Vec3 v, float s) {
	return (struct Vec3) { v.x / s, v.y / s, v.z / s };
}

struct Vec3 v3_cross(struct Vec3 a, struct Vec3 b) {
	return (struct Vec3) {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	};
}

float v3_length(struct Vec3 v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

float v3_dot(struct Vec3 a, struct Vec3 b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

float float_min(float a, float b) {
	if (b < a) {
		return b;
	}
	return a;
}

float degrees_to_radians(float d) {
	return d * M_PI / 180.0;
}

struct Vec3 rotate_vector(struct Quaternion q, struct Vec3 v) {
	struct Vec3 qv = { q.x, q.y, q.z };
	struct Vec3 uv = v3_cross(qv, v);
	struct Vec3 uuv = v3_cross(qv, uv);
	uv = v3_scale(uv, 2.0 * q.w);
	uuv = v3_scale(uuv, 2.0);
	return v3_add(v3_add(v, uv), uuv);
}

struct Quaternion quat_zero() {
    return (struct Quaternion){0, 0, 0, 0};
}

void quat_normalize(struct Quaternion* q) {
	float length = sqrt(q->w * q->w + q->x * q->x + q->y * q->y + q->z * q->z);
	q->w /= length;
	q->x /= length;
	q->y /= length;
	q->z /= length;
}

struct Quaternion quat_multiply(struct Quaternion q1, struct Quaternion q2) {
	struct Quaternion result;
	result.w = q1.w * q2.w - q1.x * q2.x - q1.y * q2.y - q1.z * q2.z;
	result.x = q1.w * q2.x + q1.x * q2.w + q1.y * q2.z - q1.z * q2.y;
	result.y = q1.w * q2.y - q1.x * q2.z + q1.y * q2.w + q1.z * q2.x;
	result.z = q1.w * q2.z + q1.x * q2.y - q1.y * q2.x + q1.z * q2.w;
	return result;
}

struct Quaternion quat_conjugate(struct Quaternion q) {
	struct Quaternion result;
	result.w = q.w;
	result.x = -q.x;
	result.y = -q.y;
	result.z = -q.z;
	return result;
}

struct Vec3 ray_at(struct Ray r, float t) {
    return v3_add(r.origin, v3_scale(r.direction, t));
}
