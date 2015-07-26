#ifndef ARGLYZER
#define ARGLYZER

#define MAXLEN 32

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    char name;
    char long_name[MAXLEN];
    char **param;
    unsigned short found;
    unsigned short nparams;
} Option;

int analyze(int argc, char *argv[], OptionPtr *res);

#endif
