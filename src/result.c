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

#include "result.h"
#include "option.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

ResultPtr create_result(OptionsListPtr options_list, int max_args)
{
    if(max_args <= 0)
        return NULL;

    ResultPtr result = (ResultPtr) malloc(sizeof(Result));

    result -> options = options_list;

    result -> params = (char **) malloc(sizeof(char *) * (max_args + 1));
    memset(result -> params, 0, max_args + 1);

    return result;
}

int print_result(ResultPtr result)
{
    if(result == NULL)
        return 1;

    if(result -> options == NULL)
        return 2;

    OptionPtr opt_ptr;

    for(opt_ptr = result -> options -> lh_first; opt_ptr != NULL; opt_ptr = opt_ptr -> entries.le_next)
        print_option(opt_ptr);

    char **params_ptr;

    for(params_ptr = result -> params; *params_ptr != NULL; ++params_ptr)
        printf("Param[%d] : %s\n", params_ptr - result -> params, *params_ptr);

    return 0;
}

int free_result(ResultPtr result)
{
    if(result == NULL)
        return 1;

    char **params_ptr;

    for(params_ptr = result -> params; *params_ptr != NULL; ++params_ptr)
        free(*params_ptr);

    free(result -> params);

    free(result);

    return 0;
}
