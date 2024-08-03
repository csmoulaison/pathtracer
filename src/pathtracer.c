#include "pathtracer.h"
#include <stdio.h>

void render(struct World* world, uint32_t width, uint32_t height, uint32_t* out_pixels) {
    struct Vec3 cam_center = world->camera.position;

    // Calculate direction based on yaw and pitch
    float yaw = world->camera.orientation.x;
    float pitch = world->camera.orientation.y;
    float dir_x = cos(yaw) * cos(pitch);
    float dir_y = sin(yaw) * cos(pitch);
    float dir_z = sin(pitch);
    struct Vec3 cam_orientation = v3_normalize((struct Vec3){ dir_x, dir_y, dir_z });
    cam_orientation = v3_add(cam_orientation, cam_center);
    cam_orientation = (struct Vec3){cam_center.x, cam_center.y, cam_center.z - 1};
    cam_orientation.x += yaw;

    float focal_length = v3_length(v3_sub(cam_center, cam_orientation));

    // Calculate basis vectors for cam
    struct Vec3 up = {0, 1, 0};
    struct Vec3 cam_w = v3_unit(v3_sub(cam_center, cam_orientation));
    struct Vec3 cam_u = v3_unit(v3_cross(up, cam_w));
    struct Vec3 cam_v = v3_cross(cam_w, cam_u);

    // Viewport size
    struct Vec2 view_size;
    {
        float fov_theta = degrees_to_radians(world->camera.fov);
        float h = tan(fov_theta / 2);
        view_size.y = 2 * h * focal_length;
        view_size.x = view_size.y * (width / height);
    }

    // UV coordinates here represent the 2d viewport space without cam context.
    // view_x are vectors spanning the length of the viewport in uv space, with
    // v being inverted due to image and camera space y coord being flipped.
    struct Vec3 view_u = v3_mult((struct Vec3){ view_size.x, 0, 0 }, cam_u);
    struct Vec3 view_v = v3_mult(
        (struct Vec3){ 0, view_size.y, 0 }, 
        v3_scale(cam_v, -1)
    );
    view_v = v3_mult(
        (struct Vec3){0, view_size.y, 0},
        (struct Vec3){-cam_v.x, -cam_v.y, -cam_v.z}
    );

    // Size of a pixel in uv space
    struct Vec3 pixel_size_u = v3_div(view_u, width);
    struct Vec3 pixel_size_v = v3_div(view_v, height);

    // Upper left of view in world space
    struct Vec3 view_upper_left = cam_center;
    view_upper_left = v3_sub(view_upper_left, (struct Vec3){ 0, 0, focal_length * cam_w.z });
    view_upper_left = v3_sub(view_upper_left, v3_div(view_u, 2));
    view_upper_left = v3_sub(view_upper_left, v3_div(view_v, 2));

    struct Vec3 pixel_upper_left;
    {
        struct Vec3 pixel_size_uv = v3_add(pixel_size_u, pixel_size_v);
        struct Vec3 half_pixel_size_uv = v3_scale(pixel_size_uv, 0.5);

        pixel_upper_left = v3_add(view_upper_left, half_pixel_size_uv);
    }

	for (uint32_t y = 0; y < height; ++y) {
		for (uint32_t x = 0; x < width; ++x) {
            struct Vec3 pixel_center; 
            {
                struct Vec3 pixel_u = v3_scale(pixel_size_u, x);
                struct Vec3 pixel_v = v3_scale(pixel_size_v, y);
                struct Vec3 pixel_uv = v3_add(pixel_u, pixel_v);
                pixel_center = v3_add(pixel_upper_left, pixel_uv);
            }

            struct Ray ray = { cam_center, v3_sub(pixel_center, cam_center) };

			// Move pixel pointer
			uint32_t* p = out_pixels;
			p += y * width + x;

			// Check for intersection
			struct Intersection intersection = intersect_world(&ray, world);
			if (intersection.intersected == 1) {
                struct Vec3 color = v3_scale(
                    (struct Vec3){intersection.normal.x + 1, intersection.normal.y + 1, intersection.normal.z + 1},
                    0.5
                );

                // TODO vec3 to uint32_t
                uint32_t c32 = 0;
                ((uint8_t*)&c32)[0] = (uint8_t)(color.x * 250);
                ((uint8_t*)&c32)[1] = (uint8_t)(color.y * 250);
                ((uint8_t*)&c32)[2] = (uint8_t)(color.z * 250);
                ((uint8_t*)&c32)[3] = 255;

                *p = c32;
			}
			else {
                *p = sky_color(ray);
			}

		}
	}
}

uint32_t sky_color(struct Ray r) {
    struct Vec3 unit_direction = v3_unit(r.direction);
    float a = 0.5 * (unit_direction.y + 1.0);
    struct Vec3 color1 = { 1, 1, 1 };
    struct Vec3 color2 = { 0.2, 0.7, 1 };
    struct Vec3 color = v3_add(v3_scale(color1, 1 - a), v3_scale(color2, a));

    // TODO vec3 to uint32_t
    uint32_t result = 0;
    ((uint8_t*)&result)[0] = (uint8_t)(color.x * 250);
    ((uint8_t*)&result)[1] = (uint8_t)(color.y * 250);
    ((uint8_t*)&result)[2] = (uint8_t)(color.z * 250);
    ((uint8_t*)&result)[3] = 255;
    return result;
}

struct Intersection intersect_world(struct Ray* ray, struct World* world) {
	struct Intersection closest_intersection;
	closest_intersection.intersected = 0;
	float closest_t = INFINITY;

	// Eventually in a for loop for all geometry
	for (int i = 0; i < 2; ++i) {
		struct Sphere* sphere = &world->sphere;
		if (i == 1) {
			sphere = &world->floor;
		}

		struct Intersection intersection = intersect_sphere(ray, sphere);
		if (intersection.intersected == 1 && intersection.t < closest_t) {
			closest_intersection.intersected = 1;
			closest_intersection = intersection;
			closest_t = intersection.t;
		}
	}

	return closest_intersection;
}

// TODO outward normals
struct Intersection intersect_sphere(struct Ray* r, struct Sphere* s) {
	struct Intersection result;
	result.intersected = 0;
	result.point = (struct Vec3){ 0, 0, 0 };
	result.t = 0;

	struct Vec3 oc = v3_sub(s->center, r->origin);
	float a = v3_dot(r->direction, r->direction);
	float b = -2.0 * v3_dot(r->direction, oc);
	float c = v3_dot(oc, oc) - s->radius * s->radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant >= 0) {
		float sqrt_discriminant = sqrt(discriminant);
		float t1 = (-b - sqrt_discriminant) / (2.0 * a);
		float t2 = (-b + sqrt_discriminant) / (2.0 * a);

		if (t1 >= 0 || t2 >= 0) {
			result.intersected = 1;
			result.t = float_min(t1, t2);
			result.point = v3_add(r->origin, v3_scale(r->direction, result.t));
            // TODO Calculated every time there's an intersection.
            // Thrown away if a closer intersection occurs. Any fixes?
            result.normal = v3_unit(v3_sub(ray_at(*r, result.t), s->center));
			return result;
		}
	}
	return result;
}
