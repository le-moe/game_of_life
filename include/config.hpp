#ifndef CONFIG_HPP
#define CONFIG_HPP
#include <stdlib.h>

#define WIDTH 100
#define HEIGHT 100
#define SCALE 10
#define WINW ( WIDTH * SCALE)
#define WINH ( HEIGHT * SCALE)

#define TRUE 1
#define FALSE 0
#define SPEED 300                 /* update period in ms */
#define RDENSITY 15               /* white random density in %age */

#define DEBUG FALSE
#define I(X,Y) (Y*WIDTH + X)*CHANNELS


typedef unsigned int u4;
typedef unsigned char u1;


struct Config {
    u4 window_x;
    u4 window_y;
    u4 ncell_x;
    u4 ncell_y;
    u4 scale_x;
    u4 scale_y;
    u4 tot_cells;

    Config(u4 width, u4 height, u4 scale)
    : window_x(width), window_y(height), scale_x(scale), scale_y(scale)
    {
        ncell_x = window_x / scale_x;
        ncell_y = window_y / scale_y;
        tot_cells = ncell_x * ncell_y;
    }
};

#endif // CONFIG_HPP