#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // take name argument, loop through candidates to see if name matches
    for (int i = 0; i < candidate_count; i++)
    {
        // if name matches a name from the candidates array
        if (strcmp(name, candidates[i].name) == 0)
        {
            // add a vote to that candidate
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // create an int variable to hold the highest number of votes
    int max_votes = 0;

    // iterate through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // if a candidate has more votes than the current max votes
        if (candidates[i].votes > max_votes)
        {
            // set max votes to that candidates vote count
            max_votes = candidates[i].votes;
        }
    }

    // iterate through candidates again
    for (int j = 0; j < candidate_count; j++)
    {
        // find person with max votes
        if (candidates[j].votes == max_votes)
        {
            printf("%s\n", candidates[j].name);
        }
    }

    return;
}