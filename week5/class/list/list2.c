// formulation of an array using dynamic memory allocation

#include <stdio.h>

int main(void)
{
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // time passes

    // this code tells the list pointer to point at an new chunk of
    // memory, effectively forgetting the first chunck of memory
    list = malloc(4 * sizeof(int));
    list[3] = 4;

}