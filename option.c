#include "option.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

OptionPtr create_option(char name, char *long_name, unsigned short nparams)
{
    if(!isalpha(name))
        return NULL;

    if(long_name != NULL && (strlen(long_name) == 0 || strlen(long_name) > MAXLEN))
        return NULL;

    OptionPtr option = (OptionPtr) malloc(sizeof(Option));

    option -> name = name;
    option -> long_name = (long_name != NULL) ? (char *) malloc(sizeof(char) * (strlen(long_name) + 1)) : NULL;
    option -> nparams = nparams;
    option -> found = 0;
    memset(option -> param, NULL, MAXPARAMS);

    return option;
}

int free_option(OptionPtr option)
{
    if(option == NULL)
        return 1;

    if(option -> long_name != NULL)
        free(option -> long_name);

    free(option);

    return 0;
}
