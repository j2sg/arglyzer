#ifndef OPTION_H
#define OPTION_H

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
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
