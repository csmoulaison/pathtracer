#include "world.h"

/*
struct Quaternion quat_from_axes(struct Vec3 forward, struct Vec3 up) {
    struct Vec3 right = v3_cross(forward, up);
    struct Quaternion result;

    float trace = 1.0 + right.x + up.y + forward.z;

    if (trace > 1e-6) {
        float s = 0.5 / sqrt(trace);
        result.w = 0.25 / s;
        result.x = (up.z - forward.y) * s;
        result.y = (forward.x - right.z) * s;
        result.z = (right.y - up.x) * s;
    }
    else {
        if (right.x > up.y && right.x > forward.z) {
            float s = 2.0 * sqrt(1.0 + right.x - up.y - forward.z);
            result.w = (up.z - forward.y) / s;
            result.x = 0.25 * s;
            result.y = (up.x + right.y) / s;
            result.z = (forward.x + right.z) / s;
        }
        else if (up.y > forward.z) {
            float s = 2.0 * sqrt(1.0 + up.y - right.x - forward.z);
            result.w = (forward.x - right.z) / s;
            result.x = (up.x + right.y) / s;
            result.y = 0.25 * s;
            result.z = (forward.y + up.z) / s;
        }
        else {
            float s = 2.0 * sqrt(1.0 + forward.z - right.x - up.y);
            result.w = (right.y - up.x) / s;
            result.x = (forward.x + right.z) / s;
            result.y = (forward.y + up.z) / s;
            result.z = 0.25 * s;
        }
    }

    return result;
}
*/
