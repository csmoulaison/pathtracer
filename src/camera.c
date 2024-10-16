#include "camera.h"

void camera_look(struct Vec2 look_direction, struct Camera* camera) {
    const float max_pitch = 89;
      
    camera->yaw += look_direction.x;
    camera->pitch += look_direction.y;
    if(camera->pitch > max_pitch) {
        camera->pitch = max_pitch;
    } else if (camera->pitch < -max_pitch) {
        camera->pitch = -max_pitch;
    }
}

struct Vec3 camera_forward(float yaw) {
    struct Vec3 f = {0, 0, -1};
    float cosy = cos(yaw);
    float siny = sin(yaw);
            
    struct Vec3 cam_forward = {
        cosy * f.x + siny * f.z,
        f.y,
        -siny * f.x + cosy * f.z
    };

    return cam_forward;
}

/* originally from camera_look function
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
