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

#ifndef OPTION_H
#define OPTION_H

#include "queue.h"

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    LIST_ENTRY(OptionType) entries;
    char name;
    char *long_name;
    unsigned short nparams;
    unsigned short found;
    char **param;
} Option;

OptionPtr create_option(char name, char *long_name, unsigned short nparams);
int print_option(OptionPtr option);
int free_option(OptionPtr option);

#endif
