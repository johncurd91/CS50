#include <cs50.h>
#include <stdio.h>


int main(void)
{
    // Prompt user for height
    int height;
    do
    {
        height = get_int("Enter height: ");
    }
    while (height < 1 || height > 8);
    
    // Build pyramid
    for (int i = 0; i < height; i++)
    {
        // Print spaces
        for (int j = i; j < height - 1; j++)
        {
            printf(" ");
        }
        
        // Print left hashes
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }
        
        // Print gap
        printf("  ");
        
        // Print right hashes
        for (int k = i + 1; k > 0; k--)
        {
            printf("#");
        }
        
        // Move to next row
        printf("\n");
    }
}
    