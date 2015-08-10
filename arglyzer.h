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

#ifndef ARGLYZER
#define ARGLYZER

#include "result.h"
#include "option.h"

ResultPtr analyze(int argc, char **argv, OptionPtr *opts);
static OptionPtr find_option(char opt, OptionPtr *options);
static OptionPtr find_long_option(char *opt, OptionPtr *options);
static int assign_param(char *arg, char **param);

#endif
