#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define N 26

int score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Compute the score of each word
    int score1 = score(word1);
    int score2 = score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int score(string word)
{
    // Return the score of the word
    int sc = 0, word_length = strlen(word);
    int value_of_letters[N] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                               1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0, j; i < word_length; i++)
    {
        j = toupper(word[i]) - 'A'; // Determine the index of the letter in
                                    // value_of_letters if exists
        if (0 <= j && j < N)
        {
            sc += value_of_letters[j];
        }
    }

    return sc;
}
