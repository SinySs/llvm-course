#include <stdlib.h>
#include <stdbool.h>
#include "graphics.h"


static int grid[GRID_WIDTH * GRID_HEIGHT];
static int new_grid[GRID_WIDTH * GRID_HEIGHT];

int count_neighbors(int x, int y) {
    int count = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + GRID_WIDTH) % GRID_WIDTH;
            int ny = (y + dy + GRID_HEIGHT) % GRID_HEIGHT;
            count += grid[ny * GRID_WIDTH + nx];
        }
    }
    return count;
}

void update_grid() {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int neighbors = count_neighbors(x, y);
            int idx = y * GRID_WIDTH + x;

            if (grid[idx]) {
                new_grid[idx] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[idx] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        grid[i] = new_grid[i];
    }
}

void init_grid() {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        grid[i] = rand() % 2;  
    }
}

void app() {
    init_grid();  

    bool running = true;

    while (running) {
        update_grid();
        for (int y = 0; y < GRID_HEIGHT; y++) {
            for (int x = 0; x < GRID_WIDTH; x++) {
                put_pixel(x, y, grid[y * GRID_WIDTH + x]);
            }
        }

        flush();
    }
}