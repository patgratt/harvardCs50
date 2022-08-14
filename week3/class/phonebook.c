#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David", "Patrick"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    for (int i = 0; i < 2; i++)
    {
        // new function strcmp, if two strings are the same, it will return 0
        if (strcmp(names[i], "David")  == 0)
        {
            printf("Found %s\n", numbers[i]);
            // return 0 means complete script, the script worked correctly
            return 0;
        }
    }
    printf("Not found\n");
    // return 1 means exit script because there is some error
    return 1;
}