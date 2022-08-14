// import cs50 library
#include <cs50.h>
// import standard io library
#include <stdio.h>

int main(void)
{
     // Prompt user for height
    int height;
    do
    {
        height = get_int("Input a height from 1-8 ");
    }
        // if height is less than 1 or greater than 8 (or not an integer at all), go back one step
    while (height < 1 || height > 8);

    // iterate in range(height), for each row
    for (int i = 0; i < height; i++)
    {
        // for each column, iterate i times, stop at (i+1)
        for (int j = 0; j < (i+1); j++)
        {
            //print a brick
            printf("#");
        }

        // move to the next row
        printf("\n");
    }
}