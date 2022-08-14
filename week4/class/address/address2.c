#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;
    printf("%p\n", p); // hexadecimal shit (0x7fff112e241c)
    // here this star is being used as a dereference operator, so it will
    // go to the location in the memory that the pointer is pointing to and
    // retrieve the value stored there
    printf("%i\n", *p); // 50
}