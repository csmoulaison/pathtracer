#include "pathtracer.h"
#include "input.h"
#include "platform.h"
#include "matrix_transform.h"
#include "sphere.h"
#include "world.h"

int main(int argc, char** argv) {
    struct Quaternion m[4];
    matrix_translate(v3_zero(), m);

	struct World world;
	world.camera.fov = 60;
	world.camera.position = (struct Vec3){ 0, 0, 0 };
	//world.camera.orientation = (struct Vec2){ atan2(0, -1), asin(0) };
	world.camera.yaw = 0;
	world.camera.pitch = 0;
	world.spheres[0].center = (struct Vec3){0, 0, -2};
	world.spheres[0].radius = 0.5;
	world.spheres[1].center = (struct Vec3){0, -100, 0};
	world.spheres[1].radius = 99;
	world.spheres_len = 2;

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

		float look_scalar = 0.1;
		struct Vec2 look_direction = (struct Vec2){ 0, 0 };
		look_direction.x -= input.left;
		look_direction.x += input.right;
		look_direction.y -= input.up;
		look_direction.y += input.down;
		look_direction.x *= look_scalar;
		look_direction.y *= look_scalar;
		camera_look(look_direction, &world.camera);
		
		struct Vec3 cam_forward = camera_forward(world.camera.yaw);
		struct Vec3 cam_right = v3_cross(cam_forward, (struct Vec3){0, 1, 0});
		
		struct Vec2 move_direction = (struct Vec2){ 0, 0 };
		move_direction.x -= input.a;
		move_direction.x += input.d;
		move_direction.y -= input.w;
		move_direction.y += input.s;
		
		struct Vec3 cam_delta = v3_zero();
		cam_delta = v3_scale(cam_forward, move_direction.y);
		cam_delta = v3_add(cam_delta, v3_scale(cam_right, move_direction.x));
		float move_scalar = 0.2;
		cam_delta = v3_scale(cam_delta, move_scalar);
			                   
		world.camera.position = v3_add(world.camera.position, cam_delta);
		
		struct Quaternion mat_view[4];
		struct Vec3 inverse_cam_pos = {-world.camera.position.x, -world.camera.position.y, -world.camera.position.z};
		matrix_view(inverse_cam_pos, world.camera.pitch, world.camera.yaw, mat_view);

		// for nother test
		struct Quaternion mat_wtc[4];
		matrix_world_to_cam(world.camera.position, world.camera.pitch, world.camera.yaw, mat_wtc);
				
		struct Sphere spheres[SPHERES_MAX];
		for(uint8_t i = 0; i < world.spheres_len; i++) {		
			spheres[i].radius = world.spheres[i].radius;
			spheres[i].center = v3_zero();
			
			struct Quaternion mat_translate[4];
			matrix_translate(world.spheres[i].center, mat_translate);

			struct Quaternion mat_world_view[4];
			multmat_44_44(mat_wtc, mat_translate, mat_world_view);
			
			multmat_44_3(mat_world_view, spheres[i].center, &spheres[i].center);
		}

		render(spheres, world.spheres_len, platform.canvas_size.x, platform.canvas_size.y, platform.canvas_pixels);

	    present_platform(&platform);
	}

	return 0;
}
