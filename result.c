#include "result.h"
#include <stdlib.h>
#include <string.h>

ResultPtr create_result(int max_args)
{
    if(max_args <= 0)
        return NULL;

    ResultPtr result = (ResultPtr) malloc(sizeof(Result));

    result -> options = (OptionPtr *) malloc(sizeof(OptionPtr) * (max_args + 1));
    memset(result -> options, NULL, max_args + 1);

    result -> params = (char **) malloc(sizeof(char *) * (max_args + 1));
    memset(result -> params, NULL, max_args + 1);

    return result;
}

int free_result(ResultPtr result)
{
    if(result == NULL)
        return 1;

    while(result -> options++ != NULL)
        free_option(*result -> options);

    free(result -> options);

    while(result -> params++ != NULL)
        free(*result -> params);

    free(result -> params);

    free(result);

    return 0;
}