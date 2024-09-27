#define WIDTH 800
#define HEIGHT 600
#define CELL_SIZE 1
#define GRID_WIDTH (WIDTH / CELL_SIZE)
#define GRID_HEIGHT (HEIGHT / CELL_SIZE)

void flush();
void put_pixel(int x, int y, int color);
void sim_init();
void sim_exit();
void app();
int sim_rand();