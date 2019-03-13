#include <stdio.h>
#include <stdlib.h>

struct{
    int i;
}typedef t_struct,*p_struct;

void run_monolithic_array() {
    printf("Running monolithic array\n");

    p_struct array = malloc(sizeof(t_struct)*5);

    for(int i = 0 ;i < 5; i++){
        array[i].i = i;
    }

    free(array);
    array = NULL;
}
