#include "vector.h"

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

struct Vec3 v3_inverse(struct Vec3 v) {
    return (struct Vec3){
        1 / v.x,
        1 / v.y,
        1 / v.z
    };
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
