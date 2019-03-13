#include <stdio.h>
#include <stdlib.h>

struct{
    int i;
}typedef t_type,*p_type;

void run_array_of_pointers() {
    printf("Running array of pointers\n");

    p_type* array = malloc(sizeof(p_type)*5);

    for(int i = 0;i < 5;i++){
        array[i] = malloc(sizeof(t_type));
        array[i]->i = i;
    }

    for(int i = 0;i < 5;i++){
        free(array[i]);
        array[i] = NULL;
    }

    free(array);
    array = NULL;
}
