#ifndef ARGLYZER
#define ARGLYZER

#define MAXLEN 32

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    char name;
    char long_name[MAXLEN];
    unsigned short nparams;
    unsigned short found;
    char **param;
} Option;

int analyze(int argc, char **argv, OptionPtr *res);
static OptionPtr find_option(char opt, OptionPtr *options);
static OptionPtr find_long_option(char *opt, OptionPtr *options);

#endif
