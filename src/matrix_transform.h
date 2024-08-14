#pragma once
#include "vector.h"
#include "quaternion.h"

void matrix_world_to_cam(struct Vec3 cam_pos, float pitch, float yaw, struct Quaternion* out);
void matrix_view(struct Vec3 cam_pos, float pitch, float yaw, struct Quaternion* out);
void matrix_translate(struct Vec3 t, struct Quaternion* out);
void matrix_rotate_cam(float pitch, float yaw, struct Quaternion* out);
void multmat_44_44(struct Quaternion* m1, struct Quaternion* m2, struct Quaternion* out);
void multmat_44_4(struct Quaternion* m, struct Quaternion q, struct Quaternion* out);
void multmat_44_3(struct Quaternion* m, struct Vec3 v, struct Vec3* out);
