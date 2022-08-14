#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // create string
    string s = "HI!";
    // create pointer that points to the first letter in the string s (array of chars),  which is litterally what a string is
    char *p = &s[0];
    // print the pointer
    printf("%p\n", p); // 0x561b30ff9004
    // print the pointer of s
    printf("%p\n", s); // 0x561b30ff9004
    printf("%p\n", &s[0]); // 0x561b30ff9004 -> these first three are all the same
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);
}