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

#include "option.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>

OptionPtr create_option(char name, char *long_name, unsigned short nparams)
{
    if(!isalpha(name))
        return NULL;

    if(long_name != NULL && strlen(long_name) < 3)
        return NULL;

    OptionPtr option = (OptionPtr) malloc(sizeof(Option));

    option -> name = name;

    option -> long_name = (long_name != NULL) ? (char *) malloc(sizeof(char) * (strlen(long_name) + 1)) : NULL;
    if(long_name != NULL)
        strcpy(option -> long_name, long_name);

    option -> nparams = nparams;

    option -> found = 0;

    if(option -> nparams == 0)
        option -> param = NULL;
    else {
        option -> param = (char **) malloc(sizeof(char *) * (option -> nparams + 1));
        memset(option -> param, 0, option -> nparams + 1);
    }

    return option;
}

int print_option(OptionPtr option)
{
    if(option == NULL)
        return 1;

    printf("Option[-%c] : long name=%s nparams=%d found=%d params={",
           option -> name,
           option -> long_name != NULL ? option -> long_name : "",
           option -> nparams,
           option -> found);

    if(option -> param != NULL) {
        char **param_ptr;

        for(param_ptr = option -> param; *param_ptr != NULL; ++param_ptr)
            printf("%s ", *param_ptr);
    }
    printf("}\n");

    return 0;
}

int free_option(OptionPtr option)
{
    if(option == NULL)
        return 1;

    if(option -> long_name != NULL)
        free(option -> long_name);

    if(option -> param != NULL)
        free(option -> param);

    free(option);

    return 0;
}
