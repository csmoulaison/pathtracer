#include "world.h"

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

void camera_look(struct Vec2 look_direction, struct Camera* camera) {
    camera->orientation.x += look_direction.x;
    camera->orientation.y += look_direction.y;

    /*
    // Calculate rotation quaternion for vertical rotation
    struct Quaternion vertical_rotation = {
        sin(look_direction.y * 0.5f),  // x
        0.0f,                          // y
        0.0f,                          // z
        cos(look_direction.y * 0.5f)   // w
    };

    // Calculate rotation quaternion for horizontal rotation
    struct Quaternion horizontal_rotation = {
        0.0f,                           // x
        sin(look_direction.x * 0.5f),   // y
        0.0f,                           // z
        cos(look_direction.x * 0.5f)    // w
    };

    // Apply rotations to camera's local axes
    struct Vec3 local_forward = rotate_vector(camera->orientation, (struct Vec3) { 0.0f, 0.0f, -1.0f });
    struct Vec3 local_right = rotate_vector(camera->orientation, (struct Vec3) { 1.0f, 0.0f, 0.0f });
    struct Vec3 local_up = v3_cross(local_right, local_forward);

    struct Quaternion rotation = quat_multiply(vertical_rotation, horizontal_rotation);

    // Rotate the local axes
    local_forward = rotate_vector(rotation, local_forward);
    local_up = rotate_vector(rotation, local_up);

    // Update the camera's orientation based on the new local axes
    camera->orientation = quat_from_axes(local_forward, local_up);
    quat_normalize(&camera->orientation);
    */
}
