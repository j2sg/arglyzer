#ifndef ARGLYZER
#define ARGLYZER

#define MAXLEN    32
#define MAXPARAMS 10

#include "option.h"

int analyze(int argc, char **argv, OptionPtr *res, char **params);
static OptionPtr find_option(char opt, OptionPtr *options);
static OptionPtr find_long_option(char *opt, OptionPtr *options);
static int assign_param(char *arg, char **param);

#endif
