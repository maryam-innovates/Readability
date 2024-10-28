#include <cs50.h>
#include <ctype.h> // Required for isalpha function
#include <math.h>
#include <stdio.h>
#include <string.h>

// Define functions
int count_letters_in_text(string text);
int count_words_in_text(string text);
int count_sentences_in_text(string text);

int main()
{
    // Input
    string text = get_string("Text: ");

    // Check for empty input
    if (strlen(text) == 0)
    {
        printf("No text entered.\n");
        return 1;
    }

    // Calling functions to get counts
    int letters = count_letters_in_text(text);
    int words = count_words_in_text(text);
    int sentences = count_sentences_in_text(text);

    // Ensure there is at least one word
    if (words == 0)
    {
        printf("Error: No words detected.\n");
        return 1;
    }

    // Computing L and S for the readability formula
    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;

    // Applying the Coleman-Liau formula
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Printing the grade level
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
        printf("Grade %d\n", index);
    }

    return 0;
}

// Function to count letters
int count_letters_in_text(string text)
{
    int length = strlen(text);
    int letter = 0;
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
    }
    return letter;
}

// Function to count words
int count_words_in_text(string text)
{
    int length = strlen(text);
    int word = 1;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            word++;
        }
    }
    return word;
}

// Function to count sentences
int count_sentences_in_text(string text)
{
    int length = strlen(text);
    int sentence = 0;
    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentence++;
        }
    }
    return sentence;
}
