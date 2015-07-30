#ifndef OPTION_H
#define OPTION_H

typedef struct OptionType *OptionPtr;

typedef struct OptionType
{
    char name;
    char long_name[MAXLEN];
    unsigned short nparams;
    unsigned short found;
    char *param[MAXPARAMS];
} Option;

#endif
