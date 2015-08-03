#ifndef OPTION_H
#define OPTION_H

#define MAXLEN    32
#define MAXPARAMS 10

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    char name;
    char long_name[MAXLEN + 1];
    unsigned short nparams;
    unsigned short found;
    char *param[MAXPARAMS];
} Option;

OptionPtr create_option(char name, char *long_name, unsigned short nparams);
int free_option(OptionPtr option);

#endif
