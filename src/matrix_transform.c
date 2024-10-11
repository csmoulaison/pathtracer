#include "matrix_transform.h"

void matrix_world_to_cam(struct Vec3 cam_pos, float pitch, float yaw, struct Quaternion* out) {
    float siny = sin(yaw);
    float sinx = sin(pitch);
    float cosy = cos(yaw);
    float cosx = cos(pitch);

    float camx = cam_pos.x;
    float camy = cam_pos.y;
    float camz = cam_pos.z;
    
    out[0] = (struct Quaternion){-siny,        cosy,         0,     camx * siny - camy * cosy};
    out[1] = (struct Quaternion){-sinx * cosy, -sinx * siny, cosx,  sinx * (camx * cosy + camy * siny) - camz * cosx};
    out[2] = (struct Quaternion){-cosx * cosy, -cosx * siny, -sinx, cosx * (camx * cosy + camy * siny) + camz * sinx};
    out[3] = (struct Quaternion){0,            0,            0,     1};
}

void matrix_view(struct Vec3 cam_pos, float pitch, float yaw, struct Quaternion* out) {
    struct Quaternion mat_translate[4];
    matrix_translate(cam_pos, mat_translate);

    struct Quaternion mat_rot[4];
    matrix_rotate_cam(pitch, yaw, mat_rot);

    multmat_44_44(mat_rot, mat_translate, out);
}

void matrix_translate(struct Vec3 t, struct Quaternion* out) {
    out[0] = (struct Quaternion){1, 0, 0, t.x};
    out[1] = (struct Quaternion){0, 1, 0, t.y};
    out[2] = (struct Quaternion){0, 0, 1, t.z};
    out[3] = (struct Quaternion){0, 0, 0, 1};
}

void matrix_rotate_cam(float pitch, float yaw, struct Quaternion* out) {
    float cos_rx = cos(-pitch);
    float sin_rx = sin(-pitch);
    float cos_ry = cos(-yaw);
    float sin_ry = sin(-yaw);

    struct Quaternion xr_mat[4];
    xr_mat[0] = (struct Quaternion){1, 0, 0, 0};
    xr_mat[1] = (struct Quaternion){0, cos_rx, -sin_rx, 0};
    xr_mat[2] = (struct Quaternion){0, sin_rx, cos_rx, 0};
    xr_mat[3] = (struct Quaternion){0, 0, 0, 1};

    struct Quaternion yr_mat[4];
    yr_mat[0] = (struct Quaternion){cos_ry, 0, sin_ry, 0};
    yr_mat[1] = (struct Quaternion){0, 1, 0, 0};
    yr_mat[2] = (struct Quaternion){-sin_ry, 0, cos_rx, 0};
    yr_mat[3] = (struct Quaternion){0, 0, 0, 1};

    multmat_44_44(xr_mat, yr_mat, out);
}

void multmat_44_44(struct Quaternion* m1, struct Quaternion* m2, struct Quaternion* out) {
    for(uint8_t i = 0; i < 4; i++) {
        for(uint8_t j = 0; j < 4; j++) {
            float sum = 0;
            for(uint8_t k = 0; k < 4; k++) {
                sum += ((float*)&m1[i])[k] * ((float*)&m2[k])[j]; 
            }
            ((float*)&out[i])[j] = sum;
        }
    }
}

void multmat_44_4(struct Quaternion* m, struct Quaternion q, struct Quaternion* out) {
    for(int i = 0; i < 4; i++) {
        float sum = 0;
        for(int j = 0; j < 4; j++) {
            sum += ((float*)&m[i])[j] * ((float*)&q)[j];
        }
        ((float*)out)[i] = sum;
    }
}

void multmat_44_3(struct Quaternion* m, struct Vec3 v, struct Vec3* out) {
    struct Quaternion v4 = {v.x, v.y, v.z, 1};
    struct Quaternion out4;

    multmat_44_4(m, v4, &out4);
    out->x = out4.x;
    out->y = out4.y;
    out->z = out4.z;
}

void multmat_33_3(struct Vec3* m, struct Vec3 v, struct Vec3* out) {
    for(int i = 0; i < 3; i++) {
        float sum = 0;
        for(int j = 0; j < 3; j++) {
            sum += ((float*)&m[i])[j] * ((float*)&v)[j];
        }
        ((float*)out)[i] = sum;
    }
}
