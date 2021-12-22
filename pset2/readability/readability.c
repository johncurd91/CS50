#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Protoype functions
int get_letters(string s);
int get_words(string s);
int get_sentences(string s);


// Main
int main(void)
{
    // Get user input
    string s = get_string("Text: ");
    
    
    // Get letters, words, and setences
    int letters; 
    letters = get_letters(s);
    
    int words;
    words = get_words(s);
    
    int sentences;
    sentences = get_sentences(s);
    
    
    // Calculate index
    float L;
    L = letters / (float) words * 100;
    
    float S;
    S = sentences / (float) words * 100;
    
    float index;
    index = round((0.0588 * L - 0.296 * S - 15.8));
    
    
    // Output result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
    
}


// Letters function
int get_letters(string s)
{
    int letters = 0;
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            letters++;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            letters++;
        }
    }
    
    return letters;
}

// Words function
int get_words(string s)
{
    int words = 1;  // Counter starts at 1, because last word will not have space after it.
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == ' ')
        {
            words++;
        }
    }
    
    return words;
}

// Sentences function
int get_sentences(string s)
{
    int sentences = 0;
    
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentences++;
        }
    }
    
    return sentences;
}
