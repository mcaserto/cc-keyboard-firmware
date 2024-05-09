namespace hal
{
    #include "pico/stdlib.h"
    #include "hardware/gpio.h"

    class matrix
    {
        public:
        enum class diode_direction
        {
            COL_TO_ROW,
            ROW_TO_COL
        };

        // template to allow differently sized arrays for various keyboards
        template<typename row_gpio_array, typename col_gpio_array>
        matrix(row_gpio_array& row_gpio, col_gpio_array& col_gpio, diode_direction direction)
        {
            for (auto& row : row_gpio)
            {
                gpio_init(row);

                if (direction == diode_direction::COL_TO_ROW)
                {
                    // each row will need to be pulled down and act as in input
                    gpio_set_dir(row, GPIO_IN);
                    gpio_pull_down(row);
                }
                else
                {
                    // ROW_TO_COL case where each row will just be an output
                    gpio_set_dir(row, GPIO_OUT);
                }
            }

            for (auto& col : col_gpio)
            {
                gpio_init(col);

                if (direction == diode_direction::COL_TO_ROW)
                {
                    // each column will be an output
                    gpio_set_dir(col, GPIO_OUT);
                }
                else
                {
                    // ROW_TO_COL case where each column will be an input pulled down
                    gpio_set_dir(col, GPIO_IN);
                    gpio_pull_down(col);
                } 
            }
        }
    };
}