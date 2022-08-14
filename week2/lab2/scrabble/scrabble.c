#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Array for ascii values of alphabet to lineup with points array, we'll use all uppercase
int upper_letters[] = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

// Array for uppercase letters
int lower_letters[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};
int temp_points[] = {};

// idk why this is here
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // start score at 0
    int score = 0;
    // iterate through word
    for (int i = 0; i < strlen(word); i++)
    {
        // check if letter is uppercase
        if (isupper(word[i]))
        {
            // if it is uppercase
            for (int j = 0; j < sizeof(upper_letters); j++)
            {
                // iterate through until the ascii values match up
                if (word[i] == upper_letters[j])
                {
                    // assign the i position of temp points to the relevant point value
                    temp_points[i] = POINTS[j];
                    score += temp_points[i];
                }
            }
        }
        // check is the word is lowercase
        else if (islower(word[i]))
        {
            // if it is lowercase
            for (int j = 0; j < sizeof(lower_letters); j++)
            {
                // iterate through until the ascii values match up
                if (word[i] == lower_letters[j])
                {
                    // assign the i position of temp points to the relevant point value
                    temp_points[i] = POINTS[j];
                    score += temp_points[i];
                }
            }
        }
        // if the char is not a letter this moves to next char
        else
        {
            i += 1;
        }
    }
    // return score
    return score;

}
