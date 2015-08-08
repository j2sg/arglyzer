#include <stdio.h>
#include "arglyzer.h"

#define N_OPTIONS 4

int main(int argc, char *argv[])
{
    ResultPtr res;
    OptionPtr option_a = create_option('a', "--long-optiona", 0);
    OptionPtr option_b = create_option('b', "--long-optionb", 1);
    OptionPtr option_c = create_option('c', "--long-optionc", 2);
    OptionPtr option_d = create_option('d', "--long-optiond", 3);
    OptionPtr options[N_OPTIONS + 1] = {option_a, option_b, option_c, option_d, NULL};

    if ((res = analyze(argc, argv, options)) == NULL) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }

    print_result(res);

    free_option(option_a);
    free_option(option_b);
    free_option(option_c);
    free_option(option_d);

    free_result(res);

    return 0;
}
