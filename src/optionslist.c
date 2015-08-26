#include "optionslist.h"
#include <stdlib.h>
#include <stdio.h>

OptionsListPtr create_options_list()
{
    OptionsListPtr options_list = (OptionsListPtr) malloc(sizeof(OptionsList));

    LIST_INIT(options_list);

    return options_list;
}

int add_option(OptionsListPtr options_list, OptionPtr option)
{
    if(options_list == NULL || option == NULL)
        return 1;

    LIST_INSERT_HEAD(options_list, option, entries);

    return 0;
}

int print_options_list(OptionsListPtr options_list)
{
    if(options_list == NULL)
        return 1;

    OptionPtr opt_ptr;

    for(opt_ptr = options_list -> lh_first; opt_ptr != NULL; opt_ptr = opt_ptr -> entries.le_next)
        print_option(opt_ptr);

    return 0;
}

int free_options_list(OptionsListPtr options_list)
{
    if(options_list == NULL)
        return 1;
    
    OptionPtr opt_ptr = options_list -> lh_first;
    OptionPtr next_opt_ptr;

    while(opt_ptr != NULL) {
        next_opt_ptr = opt_ptr -> entries.le_next;
        LIST_REMOVE(opt_ptr, entries);
        free_option(opt_ptr);
        opt_ptr = next_opt_ptr;
    }

    return 0;
}
