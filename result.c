#include "result.h"
#include <stdlib.h>
#include <string.h>

ResultPtr create_result(OptionPtr *opts, int max_args)
{
    if(max_args <= 0)
        return NULL;

    ResultPtr result = (ResultPtr) malloc(sizeof(Result));

    result -> options = opts;

    result -> params = (char **) malloc(sizeof(char *) * (max_args + 1));
    memset(result -> params, 0, max_args + 1);

    return result;
}

int free_result(ResultPtr result)
{
    if(result == NULL)
        return 1;

    char **params_ptr;

    for(params_ptr = result -> params; *params_ptr != NULL; ++params_ptr)
        free(*params_ptr);

    free(result -> params);

    free(result);

    return 0;
}
