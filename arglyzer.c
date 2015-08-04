#include "arglyzer.h"
#include <stdlib.h>
#include <string.h>

int analyze(int argc, char **argv, OptionPtr *res, char **params)
{
    if(argc < 1 || argv == NULL)
        return -1;

    if(res == NULL || params == NULL)
        return -2;

    OptionPtr curr_opt = NULL;
    char curr_name;
    int np = 0;

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

                curr_opt -> found++;
            }
        } else {
            if(curr_opt == NULL || (curr_opt != NULL && curr_opt -> nparams == 0)) {
                if(assign_param(argv[0], params++) < 0)
                    return -2;
            } else {
                if(np < curr_opt -> nparams) {
                    if(assign_param(argv[0], &(curr_opt -> param[np])) < 0)
                        return -2;

                    np++;
                }

                if(np == curr_opt -> nparams) {
                    if(assign_param(argv[0], params++) < 0)
                        return -2;

                    curr_opt = NULL;
                    np = 0;
                }
            }
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

static int assign_param(char *arg, char **param)
{
    if(arg == NULL)
        return -1;

    *param = (char *) malloc(sizeof(char)*(strlen(arg) + 1));

    strcpy(*param, arg);

    return 0;
}
