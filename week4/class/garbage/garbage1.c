#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int scores[3];

    for (int i = 0; i < 3; i++)
    {
        // here we haven't actually initialized the array scores and provided it with any values
        printf("%i\n", scores[i]); // prints out three zeros for me, but could be much more sensitive data stored in the memory
    }

}