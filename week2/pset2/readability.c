#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// this function prototype needs to be declared before it can be called, kinda makes sense because we are defining it outside of the main function after it's called
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// index calculation, l = total letters, s = total sentences, w = total words
float index_calc(int letters, int sens, int words);

int main(void)
{
    string input = get_string("Text: ");

    int letters_output = count_letters(input);
    int words_output = count_words(input);
    int sentences_output = count_sentences(input);
    int index_res = round(index_calc(letters_output, sentences_output, words_output));

    if (index_res >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index_res < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index_res);
    }
}

// defining count letters function
int count_letters(string text)
{
    int count_letters_res = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalnum(text[i]))
        {
            count_letters_res += 1;
        }
    }
    return count_letters_res;
}

// defining count words function
int count_words(string text)
{
    int count_words_res = 1;

    for (int i = 0; i < strlen(text); i++)
    {
        if ( isspace(text[i]) )
        {
            count_words_res += 1;
        }
    }
    return count_words_res;
}

// defining count sentence function
int count_sentences(string text)
{
    int count_sentences_res = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ( text[i] == '.' || text[i] == '!' || text[i] == '?' )
        {
            count_sentences_res += 1;
        }
    }
    return count_sentences_res;
}

// calculation function
float index_calc(int letters, int sens, int words)
{
    // average letters per 100 words
    float avg_letters = (100 * (float) letters / words);
    // average sentences per 100 words
    float avg_sens = (100 * (float) sens / words);
    // hardcoded bc its a formula, nums don't mean anything on their own
    float index_val = (0.0588 * avg_letters - 0.296 * avg_sens - 15.8);
    return index_val;
}