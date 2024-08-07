#pragma once
#include "vector.h"
#include "quaternion.h"
#include "math.h"

void matrix_view(struct Vec3 cam_center, float pitch, float yaw, struct Quaternion out[4]);
void matrix_translate(struct Vec3 t, struct Quaternion out[4]);
void matrix_rotate_cam(float pitch, float yaw, struct Quaternion out[4]);
void multmat_44_44(struct Quaternion m1[4], struct Quaternion m2[4], struct Quaternion out[4]);
