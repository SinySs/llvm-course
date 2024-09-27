#include "graphics.h"

void swap_arrays(int **arr_1, int **arr_2) {
    int *tmp = *arr_1;
    *arr_1 = *arr_2;
    *arr_2 = tmp;
}

int count_neighbors(int x, int y, int grid[GRID_WIDTH * GRID_HEIGHT]) {
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

void update_grid(int *grid_ptr[GRID_WIDTH * GRID_HEIGHT], int *new_grid_ptr[GRID_WIDTH * GRID_HEIGHT]) {
    int *grid = *grid_ptr;
    int *new_grid = *new_grid_ptr;
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            int neighbors = count_neighbors(x, y, grid);
            int idx = y * GRID_WIDTH + x;

            if (grid[idx]) {
                new_grid[idx] = (neighbors == 2 || neighbors == 3) ? 1 : 0;
            } else {
                new_grid[idx] = (neighbors == 3) ? 1 : 0;
            }
        }
    }

    swap_arrays(grid_ptr, new_grid_ptr);
}

void init_grid(int grid[GRID_WIDTH * GRID_HEIGHT]) {
    for (int i = 0; i < GRID_WIDTH * GRID_HEIGHT; i++) {
        grid[i] = sim_rand() % 2;  
    }
}

void app() {
    int grid[GRID_WIDTH * GRID_HEIGHT];
    int new_grid[GRID_WIDTH * GRID_HEIGHT];
    int *grid_ptr = grid;
    int *new_grid_ptr = new_grid;
    
    init_grid(grid_ptr);  

    int running = 1;

    while (running) {
        update_grid(&grid_ptr, &new_grid_ptr);
        //swap_arrays(&grid_ptr, &new_grid_ptr);
        for (int y = 0; y < GRID_HEIGHT; y++) {
            for (int x = 0; x < GRID_WIDTH; x++) {
                put_pixel(x, y, grid[y * GRID_WIDTH + x]);
            }
        }

        flush();
    }
}