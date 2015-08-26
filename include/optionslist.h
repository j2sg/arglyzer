#ifndef OPTIONSLIST_H
#define OPTIONSLIST_H

#include "queue.h"
#include "option.h"

typedef struct OptionsListType *OptionsListPtr;
typedef LIST_HEAD(OptionsListType, OptionType) OptionsList;

OptionsListPtr create_options_list();
int add_option(OptionsListPtr options_list, OptionPtr option);
int print_options_list(OptionsListPtr options_list);
int free_options_list(OptionsListPtr options_list);

#endif
