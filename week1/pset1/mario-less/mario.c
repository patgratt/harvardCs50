// import cs50 library
#include <cs50.h>
// import standard io library
#include <stdio.h>

int main(void)
{
    // declare variables for height and line
    int height;
    int line;
    // Prompt user for height
    // if height is less than 1 or greater than 8 (or not an integer at all), go back one step
    do
    {
        height = get_int("Input a height from 1-8 ");
    }
    while (height < 1 || height > 8);

    // iterate in range(height), for each line
    for (line = 0; line < height; line++)
    {
        // define values of dot and hash
        int space = height - (line + 1);
        int hash = line + 1;

        // loop for printing the dots
        for (int x = 0; x < space; x++)
        {
            printf(" ");
        }

        //loop for printing the hashes
        for (int y = 0; y < hash; y++)
        {
            printf("#");
        }

        // move to the next row
        printf("\n");
    }
}