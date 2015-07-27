#include "arglyzer.h"
#include <stdlib.h>
#include <string.h>

int analyze(int argc, char **argv, OptionPtr *res)
{
    if(argc < 1 || argv == NULL)
        return -1;

    if(res == NULL)
        return -2;

    OptionPtr curr_opt;
    char curr_name;

    while(--argc > 0) {
        if((*++argv)[0] == '-') {
            if((*argv)[1] != '-') {
                while(curr_name = *++argv[0]) {
                    if((curr_opt = find_option(curr_name, res)) == NULL)
                        return -3;

                    curr_opt -> found++;
                }
            } else {
                if((curr_opt = find_long_option(argv[0], res)) == NULL)
                    return -3;

                curr_opt -> found++;            }
        } else {
            // Parameter
        }
    }

    return 0;
}

static OptionPtr find_option(char opt, OptionPtr *options)
{
    OptionPtr *ptr;

    for(ptr = options; ptr != NULL; ++ptr)
        if((*ptr) -> name == opt)
            return *ptr;

    return NULL;
}

static OptionPtr find_long_option(char *opt, OptionPtr *options)
{
    OptionPtr *ptr;

    for(ptr = options; ptr != NULL; ++ptr)
        if(strcmp((*ptr) -> long_name, opt) == 0)
            return *ptr;

    return NULL;
}
