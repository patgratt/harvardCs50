#include <stdio.h>
#include <cs50.h>
#include <string.h>

// here we are creating a new datatype called person that contains 2 arrays
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{
    // create array called people of size 2
    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1-111-111-1111";

    people[1].name = "David";
    people[1].number = "+1-222-222-2222";


    for (int i = 0; i < 2; i++)
    {
        // new function strcmp, if two strings are the same, it will return 0
        if (strcmp(people[i].name, "David")  == 0)
        {
            printf("Found %s\n", people[i].number);
            // return 0 means complete script, the script worked correctly
            return 0;
        }
    }
    printf("Not found\n");
    // return 1 means exit script because there is some error
    return 1;
}