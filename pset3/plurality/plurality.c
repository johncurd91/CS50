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
    // Loop over candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // If valid, increment votes and return true
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    // If invalid, return false
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Get highest vote count
    int highest_votes = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > highest_votes)
        {
            highest_votes = candidates[i].votes;
        }
    }
    
    // Get number of winners
    int num_of_winners = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_votes)
        {
            num_of_winners++;
        }
    }
    
    // Get winners
    string winners[num_of_winners];
    int winner_num = 0;
    
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_votes)
        {
            winners[winner_num] = candidates[i].name;
            winner_num++;
        }
    }
    
    // Print winners
    for (int i = 0; i < num_of_winners; i++)
    {
        printf("%s\n", winners[i]);
    }
}

