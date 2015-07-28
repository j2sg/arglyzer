#ifndef ARGLYZER
#define ARGLYZER

#define MAXLEN    32
#define MAXPARAMS 10

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    char name;
    char long_name[MAXLEN];
    unsigned short nparams;
    unsigned short found;
    char *param[MAXPARAMS];
} Option;

int analyze(int argc, char **argv, OptionPtr *res, char **params);
static OptionPtr find_option(char opt, OptionPtr *options);
static OptionPtr find_long_option(char *opt, OptionPtr *options);
static int assign_param(char *arg, char **param);

#endif
