#include <stdio.h>

int main(void)
{
    // create integer variable
    int n = 50;
    // create pointer variable that points to the location in the memory where n is stored
    int *p = &n;
    // displays some hexadecimal shit (0x7ffcc62d7cac)
    printf("%p\n", p);
}