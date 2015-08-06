#ifndef ARGLYZER
#define ARGLYZER

#include "result.h"
#include "option.h"

ResultPtr analyze(int argc, char **argv, OptionPtr *opts);
static OptionPtr find_option(char opt, OptionPtr *options);
static OptionPtr find_long_option(char *opt, OptionPtr *options);
static int assign_param(char *arg, char **param);

#endif
