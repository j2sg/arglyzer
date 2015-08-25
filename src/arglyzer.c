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

#include "arglyzer.h"
#include <stdlib.h>
#include <string.h>

ResultPtr analyze(int argc, char **argv, OptionPtr *opts)
{
    if(argc < 1 || argv == NULL)
        return NULL;

    if(opts == NULL)
        return NULL;

    ResultPtr res = create_result(opts, argc - 1);
    OptionPtr curr_opt = NULL;
    char curr_name;
    char **curr_param = res -> params;
    int np = 0;

    while(--argc > 0) {
        if((*++argv)[0] == '-') {
            if((*argv)[1] != '-') {
                while(curr_name = *++argv[0]) {
                    if((curr_opt = find_option(curr_name, res -> options)) == NULL)
                        return NULL;

                    curr_opt -> found++;
                }
            } else {
                if((curr_opt = find_long_option(argv[0], res -> options)) == NULL)
                    return NULL;

                curr_opt -> found++;
            }
        } else {
            if(curr_opt == NULL || (curr_opt != NULL && curr_opt -> nparams == 0)) {
                if(assign_param(argv[0], curr_param++) < 0)
                    return NULL;
            } else {
                if(np < curr_opt -> nparams) {
                    if(assign_param(argv[0], curr_opt -> param + np) < 0)
                        return NULL;

                    np++;
                }

                if(np == curr_opt -> nparams) {
                    curr_opt = NULL;
                    np = 0;
                }
            }
        }
    }

    return res;
}

static OptionPtr find_option(char opt, OptionPtr *options)
{
    OptionPtr *ptr;

    for(ptr = options; ptr != NULL; ++ptr)
        if((*ptr) -> name == opt)
            return *ptr;

    return NULL;
}

static OptionPtr find_long_option(char *opt, OptionPtr *options)
{
    OptionPtr *ptr;

    for(ptr = options; ptr != NULL; ++ptr)
        if(strcmp((*ptr) -> long_name, opt) == 0)
            return *ptr;

    return NULL;
}

static int assign_param(char *arg, char **param)
{
    if(arg == NULL)
        return -1;

    *param = (char *) malloc(sizeof(char)*(strlen(arg) + 1));

    strcpy(*param, arg);

    return 0;
}
