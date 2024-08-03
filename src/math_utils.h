#pragma once
#include <stdint.h>
#include <math.h>

struct Vec2 {
	float x;
	float y;
};

struct Vec3 {
	float x;
	float y;
	float z;
};

struct Vec2_I16 {
    uint16_t x;
    uint16_t y;
    uint16_t z;
};

struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};

struct Ray {
	struct Vec3 origin;
	struct Vec3 direction; // normalized
};

struct Intersection {
	int intersected;
	float t;
	struct Vec3 point;
    struct Vec3 normal;
};

struct Sphere {
	struct Vec3 center;
	float radius;
};

struct Vec3 v3_unit(struct Vec3 v);
struct Vec3 v3_normalize(struct Vec3 v);
struct Vec3 v3_add(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_sub(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_mult(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_scale(struct Vec3 v, float s);
struct Vec3 v3_div(struct Vec3 v, float s);
struct Vec3 v3_cross(struct Vec3 a, struct Vec3 b);
float v3_length(struct Vec3 v);
float v3_dot(struct Vec3 a, struct Vec3 b);
float float_min(float a, float b); 
float degrees_to_radians(float d);
struct Vec3 rotate_vector(struct Quaternion q, struct Vec3 v);
// Quaternions
void quat_normalize(struct Quaternion* q);
struct Quaternion quat_multiply(struct Quaternion a, struct Quaternion b);
struct Quaternion quat_conjugate(struct Quaternion q);
// Rays
struct Vec3 ray_at(struct Ray r, float t);
