#ifndef RESULT_H
#define RESULT_H

#include "option.h"

typedef struct ResultType *ResultPtr;

typedef struct ResultType
{
    OptionPtr *options;
    char **params;
} Result;

#endif
