#ifndef RESULT_H
#define RESULT_H

#include "option.h"

typedef struct ResultType *ResultPtr;

typedef struct ResultType
{
    OptionPtr *options;
    char **params;
} Result;

ResultPtr create_result(OptionPtr *opts, int max_args);
int free_result(ResultPtr result);

#endif
