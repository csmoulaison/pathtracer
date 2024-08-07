#pragma once
#include <math.h>

struct Quaternion {
	float x;
	float y;
	float z;
	float w;
};

struct Quaternion quat_zero();
void quat_normalize(struct Quaternion* q);
struct Quaternion quat_multiply(struct Quaternion a, struct Quaternion b);
struct Quaternion quat_conjugate(struct Quaternion q);
