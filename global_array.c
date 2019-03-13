#include <stdio.h>

struct{
    int i;
}typedef t_myStruct,*p_myStruct;

const int arrSize = 5;
static t_myStruct staticArr[5];

void run_global_array() {
    printf("Running global array\n");

    printf("array variable type = myStruct pointer\n");

    for(int i = 0; i < arrSize;i++)
        staticArr[i].i = i;

}
