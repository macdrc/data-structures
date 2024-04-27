#include <stdio.h>
#include <stdlib.h>
#include "header.h"

unsigned long long numbers_list[] = {
    5048451427,
    8103749840,
    8562644130,
    9079212010,
    5135494561,
    4198006759,
    7739248565,
    4088131105,
    6057944895
};

int main(int argc, char **argv){

    printf("main has run\n");
    list* hashtable_1 [SIZE];

    for (int i = 0; i < SIZE; i++){
        hashtable_1[i] = create_list();
    }

    for (int i = 0; i < 9; i++){
        add_to_hastable (hashtable_1, create_node('A'+i, numbers_list[i]));
    }

    char found = (search (hashtable_1, 4088131145))->name;
    printf("Found: %c\n", found);

    print_hashtable(hashtable_1);
    
    free_hashtable(hashtable_1);

    print_hashtable(hashtable_1);
    
    return 0;
}