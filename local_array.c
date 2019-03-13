#include <stdio.h>

struct{
    int i;
}typedef t_newStruct,*p_newStruct;

void run_local_array() {
    printf("Running local array\n");

    printf("local array variable type = t_newStruct pointer");
    static t_newStruct localArray[5];

    for(int i = 0; i < 5;i++) {
        localArray[i].i = i;
    };
}
