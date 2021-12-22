#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int start = 0;
    do
    {
        start = get_int("Enter start size: ");
    }
    while (start < 9);

    // Prompt for end size
    int end = 0;
    do
    {
        end = get_int("Enter end size: ");
    }
    while (end < start);

    // Calculate number of years until we reach threshold
    int n = start;
    int births = 0;
    int deaths = 0;
    int years = 0;
    
    while (n < end)
    {
        births = n / 3;
        deaths = n / 4;
        n = n + births - deaths;
        years++;
    }
    
    // Print number of years
    printf("Years: %i\n", years);
}