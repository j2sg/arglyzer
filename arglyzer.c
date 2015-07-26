#include "arglyzer.h"

int analyze(int argc, char *argv[], OptionPtr *res)
{
    if(argc < 1)
        return -1;

    char curr_opt;

    while(--argc > 0) {
        if((*++argv)[0] == '-') {
            if((*argv)[1] == '-') {
                // Long Option
            } else
                while(curr_opt = *++argv[0]) {
                    // Options
                }
        } else {
            // Parameter
        }
    }

    return 0;
}
