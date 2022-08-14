#include <stdio.h>

// prototype function
void swap(int a, int b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    swap(x, y);
    printf("x is %i, y is %i\n", x, y);
}

// the reason we put void in front of this function is because that is the return type, this function isn't supposed to return anythin, just
// modify existing variables
void swap(int a, int b)
{
    printf("a is %i, b is %i\n", a, b);
    int tmp = a;
    a = b;
    b = tmp;
    printf("a is %i, b is %i\n", a, b); // works for a and b but not for x and y
}