#pragma once
#include <stdbool.h>
#include <SDL.h>
#include "vector.h"
#include "input.h"

struct Platform {
    SDL_Window* window;
    struct Vec2_I16 window_size;
    SDL_Renderer* renderer;

    SDL_Texture* canvas;
    uint32_t* canvas_pixels;
    struct Vec2_I16 canvas_size;

    bool ready_to_end;
};

struct Platform init_platform();
void poll_platform_events(struct Platform* platform, struct Input* input);
void buffer_pixel(struct Platform* platform, uint32_t color, uint16_t x, uint16_t y);
void present_platform(struct Platform* platform);
