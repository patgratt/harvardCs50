#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // memory allocate space equivalent to 3 ints (4 bytes)
    int *x = malloc(3 * sizeof(int));

    // here is a mistake (on purpose), indexing should have started at 0
    x[1] = 72;
    x[2] = 73;
    // as a result of the mistake we are assigning this int value to be stored in memory that we havne't allocated
    x[3] = 33;
}