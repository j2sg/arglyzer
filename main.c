#include <stdio.h>
#include "arglyzer.h"

int main(int argc, char *argv[])
{
    if (analyze(argc, argv, 0, 0) < 0) {
        fprintf(stderr, "Error during execution.\n");
        return 1;
    }
    return 0;
}
