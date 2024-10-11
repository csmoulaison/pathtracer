#pragma once
#include <math.h>
#include <stdint.h>

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

struct Vec3 v3_zero();

// (vector) -> number
float v3_length(struct Vec3 v);

// (vector) -> vector
struct Vec3 v3_unit(struct Vec3 v);
struct Vec3 v3_normalize(struct Vec3 v);
struct Vec3 v3_inverse(struct Vec3 v);

// (vector, vector) -> vector
struct Vec3 v3_add(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_sub(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_cross(struct Vec3 a, struct Vec3 b);
struct Vec3 v3_mult(struct Vec3 a, struct Vec3 b);

// (vector, number) -> vector
struct Vec3 v3_scale(struct Vec3 v, float s);
struct Vec3 v3_div(struct Vec3 v, float s);

// (vector, vector) -> number
float v3_dot(struct Vec3 a, struct Vec3 b);
