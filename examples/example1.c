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

int main(int argc, char *argv[])
{
    ResultPtr res;
    OptionsListPtr options_list = create_options_list();

    add_option(options_list, create_option('a', "--long-optiona", 0));
    add_option(options_list, create_option('b', "--long-optionb", 1));
    add_option(options_list, create_option('c', "--long-optionc", 2));

    if ((res = analyze(argc, argv, options_list)) == NULL) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }

    print_result(res);

    free_result(res);
    free_options_list(options_list);

    return 0;
}
