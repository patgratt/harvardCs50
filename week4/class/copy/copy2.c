#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char *s = get_string("s: ");

    // create new char pointer (string), and allocate some memory with a size equivalent to the length of s + 1 for the \n
    char *t = malloc(strlen(s + 1));

    // sometimes malloc can fail if there isn't memory available
    if (t == NULL)
    {
        // return 1 to signify that somethig went wrong
        return 1;
    }


    // this loop will manually copy all of the chars of s into the new memory that we've created for t
    /*
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }
    */

   // can also just use strcopy
    strcpy(t, s);

    // put this if statement incase the user didn't input anything
    if (strlen(t) > 0)
    {
        // capitalize the first letter of the input string
        t[0] = toupper(t[0]);
    }


    printf("s: %s\n", s); // hi! -> unchanged
    printf("t: %s\n", t); // Hi! -> got capitalized

    free(t);
    return  0;
}