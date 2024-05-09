#include <stdio.h>
#include "pico/stdlib.h"
#include "hal/matrix.hpp"

constexpr uint NUM_ROWS = 4;
constexpr uint NUM_COLS = 12;

constexpr int keymap[NUM_ROWS][NUM_COLS] = {0,0,0,0,0,0,0,0,0,0,0,0,
                                            0,0,0,0,0,0,0,0,0,0,0,0,
                                            0,0,0,0,0,0,0,0,0,0,0,0,
                                            0,0,0,0,0,0,0,0,0,0,0,0};

constexpr uint row_gpio[NUM_ROWS] = {1,2,3,4};
constexpr uint col_gpio[NUM_COLS] = {1,2,3,4,5,6,7,8,9,10,11,12};

int main() {
    // setup keyboard matrix
    auto matrix = hal::matrix(row_gpio, col_gpio, hal::matrix::diode_direction::COL_TO_ROW);

    setup_default_uart();
    printf("Hello, world!\n");
    return 0;
}