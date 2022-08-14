#include <stdio.h>

int main(void)
{
    // declare variable
    int x;
    // print input question
    printf("x: ");
    // traditional way of implementing get_int
    // scanf takes input of a prescribed type (here int), and
    // declares where in memory to store that input
    scanf("%i", &x);
    printf("x: %i\n", x);
}