#include "math.h"
#include "matrix_transform.h"

void matrix_view(struct Vec3 cam_center, float pitch, float yaw, struct Quaternion out[4]) {
    struct Quaternion matrix_translate[4];
    matrix_translate(cam_center, &matrix_translate);

    struct Quaternion matrix_rot[4];
    matrix_rotate_cam(pitch, yaw, matrix_rot);
}

void matrix_translate(struct Vec3 t, struct Quaternion out[4]) {
    out[0] = (struct Quaternion){1, 0, 0, t.x};
    out[1] = (struct Quaternion){0, 1, 0, t.y};
    out[2] = (struct Quaternion){0, 0, 1, t.z};
    out[3] = (struct Quaternion){0, 0, 0, 1};
}

void matrix_rotate_cam(float pitch, float yaw, struct Quaternion out[4]) {
    f32 cos_rx = cos(-pitch)
    f32 cos_rx = cos(-pitch)
    f32 cos_ry = cos(-yaw)
    f32 cos_ry = cos(-yaw)

    struct Quaternion xr_mat[4];
    xr_mat[0] = (struct Quaternion){1, 0, 0, 0};
    xr_mat[1] = (struct Quaternion){0, cos_rx, -sin_rx, 0};
    xr_mat[2] = (struct Quaternion){0, sin_rx, cos_rx, 0};
    xr_mat[3] = (struct Quaternion){0, 0, 0, 0};

    struct Quaternion yr_mat[4];
    yr_mat[0] = (struct Quaternion){cos_ry, 0, sin_ry, 0};
    yr_mat[1] = (struct Quaternion){0, 1, 0, 0};
    yr_mat[2] = (struct Quaternion){-sin_ry, 0, cos_rx, 0};
    yr_mat[3] = (struct Quaternion){0, 0, 0, 1};

    multmat_44_44(xr_mat, yr_mat, out);
}

void multmat_44_44(struct Quaternion m1[4], struct Quaternion m2[4], struct Quaternion out[4]) {
    for(uint8_t i = 0; i < 4; i++) {
        for(uint8_t j = 0; j < 4; j++) {
            float sum = 0;
            for(uint8_t k = 0; k < 4; k++) {
                sum += m1[];
            }
        }
    }
}
