#include "arglyzer.h"
#include <stdlib.h>
#include <string.h>

ResultPtr analyze(int argc, char **argv, OptionPtr *opts)
{
    if(argc < 1 || argv == NULL)
        return NULL;

    if(opts == NULL)
        return NULL;

    ResultPtr res = create_result(opts, argc - 1);
    OptionPtr curr_opt = NULL;
    char curr_name;
    char **curr_param = res -> params;
    int np = 0;

    while(--argc > 0) {
        if((*++argv)[0] == '-') {
            if((*argv)[1] != '-') {
                while(curr_name = *++argv[0]) {
                    if((curr_opt = find_option(curr_name, res -> options)) == NULL)
                        return NULL;

                    curr_opt -> found++;
                }
            } else {
                if((curr_opt = find_long_option(argv[0], res -> options)) == NULL)
                    return NULL;

                curr_opt -> found++;
            }
        } else {
            if(curr_opt == NULL || (curr_opt != NULL && curr_opt -> nparams == 0)) {
                if(assign_param(argv[0], curr_param++) < 0)
                    return NULL;
            } else {
                if(np < curr_opt -> nparams) {
                    if(assign_param(argv[0], curr_opt -> param + np) < 0)
                        return NULL;

                    np++;
                }

                if(np == curr_opt -> nparams) {
                    if(assign_param(argv[0], curr_param++) < 0)
                        return NULL;

                    curr_opt = NULL;
                    np = 0;
                }
            }
        }
    }

    return res;
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
