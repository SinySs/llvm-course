#include <SDL2/SDL.h>
#include <stdlib.h>
#include "graphics.h"
#include <assert.h>

#define FRAME_TICKS 50

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static Uint32 ticks = 0;

void flush() {
    SDL_PumpEvents();
    assert(SDL_TRUE != SDL_HasEvent(SDL_QUIT) && "User-requested quit");
    Uint32 cur_ticks = SDL_GetTicks() - ticks;
    if (cur_ticks < FRAME_TICKS) {
        SDL_Delay(FRAME_TICKS - cur_ticks);
    }
    SDL_RenderPresent(renderer);
}

void sim_init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Init error1\n");
        return;
    }

    SDL_Window *window = SDL_CreateWindow("Conway's Game of Life",
                                          SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Quit();
        return;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    flush();
}

void sim_exit() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void put_pixel(int x, int y, int color) {
    if (color) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    } else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    }
    SDL_RenderDrawPoint(renderer, x, y);
    ticks = SDL_GetTicks();
}

int sim_rand()
{
    return rand();
}
