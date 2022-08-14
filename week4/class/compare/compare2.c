#include <cs50.h>
#include <stdio.h>

// this will output different no matter what bc string is really char *, so this compare will not work bc they will be in different places
// in the memory
// get_string returns a POINTER

int main(void)
{
    string s = get_string("s: ");
    string t = get_string("t: ");

    if (s == t)
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}