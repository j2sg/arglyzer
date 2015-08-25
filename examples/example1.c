/**
 *  This file is part of Arglyzer.
 *
 *  Copyright (c) 2015 Juan Jose Salazar Garcia jjslzgc@gmail.com
 *
 *  Arglyzer is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Arglyzer is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Arglyzer.  If not, see <http://www.gnu.org/licenses/>.
 *
 **/

#include <stdio.h>
#include <arglyzer/arglyzer.h>

#define N_OPTIONS 3

int main(int argc, char *argv[])
{
    ResultPtr res;
    OptionPtr option_a = create_option('a', "--long-optiona", 0);
    OptionPtr option_b = create_option('b', "--long-optionb", 1);
    OptionPtr option_c = create_option('c', "--long-optionc", 2);
    OptionPtr options[N_OPTIONS + 1] = {option_a, option_b, option_c, NULL};

    if ((res = analyze(argc, argv, options)) == NULL) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }

    print_result(res);

    free_option(option_a);
    free_option(option_b);
    free_option(option_c);
    free_result(res);

    return 0;
}
