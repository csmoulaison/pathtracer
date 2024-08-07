#include "quaternion.h"

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
