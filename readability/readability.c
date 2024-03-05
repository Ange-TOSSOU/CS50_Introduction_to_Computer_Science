#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int nb_letters = count_letters(text);
    int nb_words = count_words(text);
    int nb_sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    double l = (double) (nb_letters * 100) / (double) nb_words;
    double s = (double) (nb_sentences * 100) / (double) nb_words;
    long grade = (long) round(0.0588 * l - 0.296 * s - 15.8);

    // Print the grade level
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %li\n", grade);
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int text_length = strlen(text), nb_letters = 0;

    for (int i = 0; i < text_length; i++)
    {
        if (isalpha(text[i]))
        {
            nb_letters++;
        }
    }

    return nb_letters;
}

int count_words(string text)
{
    // Return the number of words in text
    int nb_words = 0, text_length = strlen(text);

    // Delete spaces at the beginning of text
    int i;
    for (i = 0; i < text_length && text[i] == ' '; i++)
        ;
    if (i == text_length)
    {
        text = NULL;
    }
    else
    {
        text += i;
        nb_words++;
    }
    // Update the length of text
    text_length = strlen(text);

    // Delete spaces at the end of text
    for (i = text_length - 1; i >= 0; i--)
    {
        if (text[i] == ' ')
        {
            text[i] = '\0';
        }
        else
        {
            break;
        }
    }

    // Count the number of words
    while (text != NULL)
    {
        text = strchr(text, ' ');
        if (text != NULL)
        {
            nb_words++;
            // Escape additional spaces
            while (*text == ' ')
            {
                text++;
            }
        }
    }

    return nb_words;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int nb_sentences = 0, text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            nb_sentences++;
        }
    }

    return nb_sentences;
}
