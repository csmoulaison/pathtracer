#include "pathtracer.h"
#include "math_utils.h"

void render(struct Vec3 origin, struct Vec3 lookat, struct Box* boxes, uint8_t boxes_len, uint32_t width, uint32_t height, uint32_t* out_pixels) {
	struct Vec3 cam_up = {0, 1, 0};
	
	//float focal_length = v3_length(v3_sub(cam_origin, cam_lookat));
	float focal_length = 1;
    float fov = 90;
	
    // Viewport size
    struct Vec2 view_size;
    {
        float fov_theta = degrees_to_radians(fov);
        float h = tan(fov_theta / 2);
        //view_size.y = 2 * h * focal_length;
        view_size.y = 1;
        view_size.x = view_size.y * ((double)width / height);
    }

    struct Vec3 cam_w = v3_unit(v3_sub(origin, lookat));
    struct Vec3 cam_u = v3_unit(v3_cross(cam_up, cam_w));
    struct Vec3 cam_v = v3_cross(cam_w, cam_u);

    // UV coordinates here represent the 2d viewport space without cam context.
    // view_x are vectors spanning the length of the viewport in uv space, with
    // v being inverted due to image and camera space y coord being flipped.
    struct Vec3 view_u = v3_scale(cam_u, view_size.x);
    struct Vec3 view_v = v3_scale(v3_scale(cam_v, -1), view_size.y);

    // Size of a pixel in uv space
    struct Vec3 pixel_size_u = v3_scale(view_u, (double)1 / width);
    struct Vec3 pixel_size_v = v3_scale(view_v, (double)1 / height);

    // Upper left of view in world space
    // struct Vec3 view_upper_left = cam_center;
    struct Vec3 view_upper_left = origin;
    //view_upper_left = v3_sub(view_upper_left, v3_scale(cam_w, focal_length));
    view_upper_left = v3_sub(view_upper_left, cam_w);
    view_upper_left = v3_sub(view_upper_left, v3_div(view_u, 2));
    view_upper_left = v3_sub(view_upper_left, v3_div(view_v, 2));

    struct Vec3 pixel_upper_left = view_upper_left;
    struct Vec3 pixel_size_uv = v3_add(pixel_size_u, pixel_size_v);
    pixel_upper_left = v3_add(pixel_upper_left, v3_scale(pixel_size_uv, 0.5));

	for (uint32_t y = 0; y < height; ++y) {
		for (uint32_t x = 0; x < width; ++x) {
            struct Vec3 pixel_center; 
            {
                struct Vec3 pixel_u = v3_scale(pixel_size_u, x);
                struct Vec3 pixel_v = v3_scale(pixel_size_v, y);
                struct Vec3 pixel_uv = v3_add(pixel_u, pixel_v);
                pixel_center = v3_add(pixel_upper_left, pixel_uv);
            }

            // NODO ~won't need ray if camera is always at origin.~
            // Wait never mind, ray needed for bounces (unless we construct "view matrix" for each bounce?)
            // TODO See above: should we construct a view matrix from the vantage point of each bounce?
            //struct Ray ray = { v3_zero(), v3_sub(pixel_center, v3_zero()) };
            struct Ray ray = { origin, v3_sub(pixel_center, origin) };

			// Move pixel pointer
			uint32_t* p = out_pixels;
			p += y * width + x;

			// Check for intersection
			struct Intersection intersection = intersect_world(ray, boxes, boxes_len);
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
			} else {
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

struct Intersection intersect_world(struct Ray ray, struct Box* boxes, uint8_t boxes_len) {
	struct Intersection closest_intersection;
	closest_intersection.intersected = 0;
	float closest_t = INFINITY;
    struct Vec3 ray_inverse_direction = v3_inverse(ray.direction);

	// Eventually in a for loop for all geometry
	for (int i = 0; i < boxes_len; i++) {
		// TODO we aren't doing this subtraction. Good?
		// spheres[i].center = v3_sub(spheres[i].center, cam_center);

		struct Intersection intersection = intersect_box(ray, ray_inverse_direction, boxes[i]);
		if (intersection.intersected == 1 && intersection.t < closest_t) {
			closest_intersection.intersected = 1;
			closest_intersection = intersection;
			closest_t = intersection.t;
		}
	}

	return closest_intersection;
}

struct Intersection intersect_box(struct Ray r, struct Vec3 r_invdir, struct Box b) {
    double tx1 = (b.min.x - r.origin.x) * r_invdir.x;
    double tx2 = (b.max.x - r.origin.x) * r_invdir.x;
    double tmin = fmin(tx1, tx2);
    double tmax = fmax(tx1, tx2);

    double ty1 = (b.min.y - r.origin.y) * r_invdir.y;
    double ty2 = (b.max.y - r.origin.y) * r_invdir.y;
    tmin = fmax(tmin, fmin(ty1, ty2));
    tmax = fmin(tmax, fmax(ty1, ty2));

    double tz1 = (b.min.z - r.origin.z) * r_invdir.z;
    double tz2 = (b.max.z - r.origin.z) * r_invdir.z;
    tmin = fmax(tmin, fmin(tz1, tz2));
    tmax = fmin(tmax, fmax(tz1, tz2));

	struct Intersection result;
    result.intersected = 0;
    if(tmax >= tmin) {
        result.intersected = 1;
    }
    //result.intersected = (tmax >= tmin);
    result.t = fmin(tmin, tmax);
    result.point = v3_add(r.origin, v3_scale(r.direction, result.t));
}

// TODO outward normals
struct Intersection intersect_sphere(struct Ray r, struct Sphere s) {
	struct Intersection result;
	result.intersected = 0;
	result.point = (struct Vec3){ 0, 0, 0 };
	result.t = 0;

	struct Vec3 oc = v3_sub(s.center, r.origin);
	float a = v3_dot(r.direction, r.direction);
	float b = -2.0 * v3_dot(r.direction, oc);
	float c = v3_dot(oc, oc) - s.radius * s.radius;
	float discriminant = b * b - 4 * a * c;

	if (discriminant >= 0) {
		float sqrt_discriminant = sqrt(discriminant);
		float t1 = (-b - sqrt_discriminant) / (2.0 * a);
		float t2 = (-b + sqrt_discriminant) / (2.0 * a);

		if (t1 >= 0 || t2 >= 0) {
			result.intersected = 1;
			result.t = float_min(t1, t2);
			result.point = v3_add(r.origin, v3_scale(r.direction, result.t));
            // TODO Calculated every time there's an intersection.
            // Thrown away if a closer intersection occurs. Any fixes?
            result.normal = v3_unit(v3_sub(ray_at(r, result.t), s.center));
			return result;
		}
	}
	return result;
}
