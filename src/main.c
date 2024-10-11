#include <stdio.h>
#include "pathtracer.h"
#include "input.h"
#include "platform.h"
#include "matrix_transform.h"
#include "sphere.h"
#include "vector.h"
#include "ray.h"
#include "world.h"
#include "math_utils.h"

int main(int argc, char** argv) {
    struct Quaternion m[4];
    matrix_translate(v3_zero(), m);

	struct World world;

	world.camera.fov = 60;
	world.camera.position = (struct Vec3){ 0, 0, 0 };
	world.camera.yaw = -90;
	world.camera.pitch = 0;

	world.spheres[0].center = (struct Vec3){0, 0, -2};
	world.spheres[0].radius = 0.5;
	world.spheres[1].center = (struct Vec3){0, -100, 0};
	world.spheres[1].radius = 99;
	world.spheres[2].center = (struct Vec3){-1, 0, 2};
	world.spheres[2].radius = 0.75;
	world.spheres_len = 3;

    world.boxes[0].min = (struct Vec3){-1, -1, -3};
    world.boxes[0].max = (struct Vec3){0, 0, -2};
    world.boxes_len = 1;

	struct Input input;
	input.left = 0;
	input.right = 0;
	input.up = 0;
	input.down = 0;
	input.a = 0;
	input.d = 0;
	input.w = 0;
	input.s = 0;
    input.q = 0;
    input.e = 0;

	struct Platform platform = init_platform();

    struct Box box = { (struct Vec3){0, 0, 0}, (struct Vec3){5, 5, 5} };
    struct Ray ray = { (struct Vec3){0, 1, 0}, (struct Vec3){0, -10, 0} };
    struct Vec3 r_invdir = v3_inverse(ray.direction);

    struct Intersection intersection = intersect_box(ray, r_invdir, box);
    if(intersection.intersected == 1) {
        printf("Yaaasss!\n");
    } else {
        printf("Noooooo!\n");
    }

	while(!platform.ready_to_end) {
	    poll_platform_events(&platform, &input);

		float look_scalar = 4;
		struct Vec2 look_direction = (struct Vec2){
            (input.right - input.left + input.e - input.q) * look_scalar,
		};

		camera_look(look_direction, &world.camera);

		float move_scalar = 0.15;
		struct Vec2 move_direction = (struct Vec2){ 0, 0 };
		move_direction.x -= input.a;
		move_direction.x += input.d;
		move_direction.y -= input.w;
		move_direction.y += input.s;

		struct Vec3 forward;
		{
			float cosy = cos(degrees_to_radians(world.camera.yaw));
			float siny = sin(degrees_to_radians(world.camera.yaw));
			float cosx = cos(degrees_to_radians(-world.camera.pitch));
			float sinx = sin(degrees_to_radians(-world.camera.pitch));
            
			forward.x = cosy * cosx;
			forward.y = sinx;
			forward.z = siny * cosx;

			forward = v3_normalize(forward);
		}
		struct Vec3 right = v3_cross((struct Vec3){0, 1, 0}, forward);

		struct Vec3 cam_delta = v3_scale(forward, -move_direction.y);
		cam_delta = v3_add(cam_delta, v3_scale(right, -move_direction.x));
		cam_delta = v3_scale(cam_delta, move_scalar);

		world.camera.position = v3_add(world.camera.position, cam_delta);

		struct Vec3 lookat = v3_add(world.camera.position, forward);
		render(world.camera.position, lookat, world.boxes, world.spheres_len, platform.canvas_size.x, platform.canvas_size.y, platform.canvas_pixels);

	    present_platform(&platform);
	}

	return 0;
}
