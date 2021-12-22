#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main(int argc, string argv[])
{
    
    // Check for valid number of CLI arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check if valid argument type
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)  // 48 and 57 are ASCII for 0 and 9
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    
    // Generate key
    int k = atoi(argv[1]);
    
    if (k > 26)
    {
        k = k % 26;
    }
    

    // Get plaintext
    string plaintext;
    plaintext = get_string("plaintext: ");
    
    
    // Generate ciphertext
    string ciphertext = plaintext;
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if letter, ignore if punctuation or number
        if (tolower(plaintext[i]) >= 'a' && tolower(plaintext[i]) <= 'z')
        {
            // Conver to ciphertext
            ciphertext[i] = (char) plaintext[i] + k;
            
            // Wrap around alphabet if value has gone beyond 'z'
            if (tolower(ciphertext[i]) >= 'z')
            {
                ciphertext[i] = (char) ciphertext[i] - 26;
            }
        }
        
    }
    
    // Output results
    printf("ciphertext: %s\n", ciphertext);
    
}
