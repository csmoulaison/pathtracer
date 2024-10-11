#include "platform.h"

#define COLOR_CHANNEL_COUNT 4

struct Platform init_platform() {
    struct Platform platform = {};
    platform.window_size.x = 512;
    platform.window_size.y = 512;
    platform.canvas_size.x = 256;
    platform.canvas_size.y = 128;
    platform.ready_to_end = false;

    SDL_Init(SDL_INIT_EVERYTHING);

    platform.window = SDL_CreateWindow(
        "pathtrace", 
        0, 
        0, 
        platform.window_size.x, 
        platform.window_size.y, 
        SDL_WINDOW_RESIZABLE
    );
    SDL_SetWindowMinimumSize(
        platform.window, 
        platform.canvas_size.x, 
        platform.canvas_size.y
    );

    platform.renderer = SDL_CreateRenderer(
        platform.window,
        -1,
        SDL_RENDERER_PRESENTVSYNC
    );
    SDL_RenderSetLogicalSize(
        platform.renderer,
        platform.canvas_size.x,
        platform.canvas_size.y
    );
    // TODO no hardcode color?
    // SDL_SetRenderDrawColor(platform.renderer, 0, 0, 0, 255);

    platform.canvas = SDL_CreateTexture(
        platform.renderer,
        SDL_PIXELFORMAT_RGBA32, 
        SDL_TEXTUREACCESS_STREAMING,
        platform.canvas_size.x,
        platform.canvas_size.y
    );
    platform.canvas_pixels = (uint32_t*)malloc(platform.canvas_size.x * platform.canvas_size.y * COLOR_CHANNEL_COUNT);

    SDL_SetRelativeMouseMode(SDL_TRUE);

    return platform;
}

void poll_platform_events(struct Platform* platform, struct Input* input) {
    input->mouse_delta_x = 0;
    input->mouse_delta_y = 0;
     
    SDL_Event event;
    while(SDL_PollEvent(&event) != 0) {
        switch(event.type) {
            case SDL_QUIT:
                platform->ready_to_end = true;
                break;
            case SDL_KEYDOWN:
                if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
                    platform->ready_to_end = true;
                }
                switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_LEFT:
                        input->left = 1;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        input->right = 1;
                        break;
                    case SDL_SCANCODE_UP:
                        input->up = 1;
                        break;
                    case SDL_SCANCODE_DOWN:
                        input->down = 1;
                        break;
                    case SDL_SCANCODE_A:
                        input->a = 1;
                        break;
                    case SDL_SCANCODE_D:
                        input->d = 1;
                        break;
                    case SDL_SCANCODE_W:
                        input->w = 1;
                        break;
                    case SDL_SCANCODE_S:
                        input->s = 1;
                        break;
                    case SDL_SCANCODE_Q:
                        input->q = 1;
                        break;
                    case SDL_SCANCODE_E:
                        input->e = 1;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch(event.key.keysym.scancode) {
                    case SDL_SCANCODE_LEFT:
                        input->left = 0;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        input->right = 0;
                        break;
                    case SDL_SCANCODE_UP:
                        input->up = 0;
                        break;
                    case SDL_SCANCODE_DOWN:
                        input->down = 0;
                        break;
                    case SDL_SCANCODE_A:
                        input->a = 0;
                        break;
                    case SDL_SCANCODE_D:
                        input->d = 0;
                        break;
                    case SDL_SCANCODE_W:
                        input->w = 0;
                        break;
                    case SDL_SCANCODE_S:
                        input->s = 0;
                        break;
                    case SDL_SCANCODE_Q:
                        input->q = 0;
                        break;
                    case SDL_SCANCODE_E:
                        input->e = 0;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_MOUSEMOTION:
                input->mouse_delta_x = event.motion.xrel;
                input->mouse_delta_y = event.motion.yrel;
                break;
            default:
                break;
        }
    }
}

void buffer_pixel(struct Platform* platform, uint32_t color, uint16_t x, uint16_t y) {
	if (x > platform->canvas_size.x || y > platform->canvas_size.y || x < 0 || y < 0) {
        return;
    }

    platform->canvas_pixels[x + y * platform->canvas_size.x] = color;
}

void present_platform(struct Platform* platform) {
    uint32_t pitch = platform->canvas_size.x * COLOR_CHANNEL_COUNT;

    SDL_LockTexture(platform->canvas, NULL, (void**)&platform->canvas_pixels, &pitch);
    //SDL_RenderClear(platform->renderer);
    SDL_UnlockTexture(platform->canvas);
    SDL_RenderCopy(platform->renderer, platform->canvas, NULL, NULL);
    SDL_RenderPresent(platform->renderer);
}
