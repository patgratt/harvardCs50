#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // create string (char pointer) s
    char *s = malloc(4);
    // ask for input
    printf("s: ");
    // function to get input, store in that pointer location
    scanf("%s", s);
    // print output
    printf("s: %s\n", s);
}