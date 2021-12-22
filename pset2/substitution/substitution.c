#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argc, string argv[])
{
    // Check number of arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    // Check for valid key
    // Generate key
    string key = argv[1];
    
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        key[i] = tolower(key[i]);
    }
    
    // Check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else
    {
        for (int i = 0, n = strlen(key); i < n; i++)
        {
            // Check for alphabetic character
            if (key[i] < 'a' || key[i] > 'z')
            {
                printf("Key must contain alphabetic characters only.\n");
                return 1;
            }

            // Check for repeated characters
            int counter = 0;
            for (int j = 0, m = strlen(key); j < m; j++)
            {
                if (key[j] == key[i])
                {
                    counter++;
                    if (counter > 1)
                    {
                        printf("Key must contain each letter only once.\n");
                        return 1;
                    }
                }
            }
        }
    }
    
    // Get user input
    string plaintext = get_string("plaintext: ");
    string ciphertext = plaintext;
    
    // Encrypt text
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            ciphertext[i] = key[(int) plaintext[i] - 97];
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            ciphertext[i] = toupper(key[(int) plaintext[i] - 65]);
        }
    }
    
    
    // Output result
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}