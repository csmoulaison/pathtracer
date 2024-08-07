#include <stdint.h>
#include "pathtracer.h"
#include "input.h"
#include "platform.h"
#include "matrix_transform.h"

int main(int argc, char** argv) {
    struct Quaternion m[4];
    matrix_translate(v3_zero(), m);

	struct World world;
	world.camera.fov = 60;
	world.camera.position = (struct Vec3){ 25, 25, 0 };
	//world.camera.orientation = (struct Vec2){ atan2(0, -1), asin(0) };
    world.camera.orientation = (struct Vec2){0, 0};
	world.sphere.center = (struct Vec3){ 25, 25, -1 };
	world.sphere.radius = 0.5;
	world.floor.center = (struct Vec3){ 27, 24.5, -2 };
	world.floor.radius = 0.75;

	struct Input input;
	input.left = 0;
	input.right = 0;
	input.up = 0;
	input.down = 0;
	input.a = 0;
	input.d = 0;
	input.w = 0;
	input.s = 0;

    struct Platform platform = init_platform();

	while(!platform.ready_to_end) {
        poll_platform_events(&platform, &input);

		// Camera movement2
		float move_scalar = 0.2;
		struct Vec2 move_direction = (struct Vec2){ 0, 0 };

		move_direction.x -= input.a;
		move_direction.x += input.d;
		move_direction.y -= input.w;
		move_direction.y += input.s;

		move_direction.x *= move_scalar;
		move_direction.y *= move_scalar;

		world.camera.position.x += move_direction.x;
		world.camera.position.z += move_direction.y;

		// Camera look rotation
		float look_scalar = 0.1;
		struct Vec2 look_direction = (struct Vec2){ 0, 0 };

		look_direction.x -= input.left;
		look_direction.x += input.right;
		look_direction.y -= input.up;
		look_direction.y += input.down;

		look_direction.x *= look_scalar;
		look_direction.y *= look_scalar;

        //world.camera.fov += input.up;
        //world.camera.fov -= input.down;

		camera_look(look_direction, &world.camera);

		//world.sphere.center.z += 0.05;
		render(&world, platform.canvas_size.x, platform.canvas_size.y, platform.canvas_pixels);

        present_platform(&platform);
	}

	return 0;
}
