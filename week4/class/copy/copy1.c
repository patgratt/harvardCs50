#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("s: ");

    // here in c when we assign t the value of s we are litterally assiging it that location in memory
    // thus both of these strings (char * pointers) have the same address now
    string t = s;

    t[0] = toupper(t[0]);

    printf("s: %s\n", s);
    printf("t: %s\n", t);
}