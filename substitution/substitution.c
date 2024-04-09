#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define NBCHARACTERS 26

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check the length of the key
    int key_length = strlen(argv[1]);
    if (key_length != NBCHARACTERS)
    {
        printf("Key must contain %i characters.\n", NBCHARACTERS);
        return 1;
    }

    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }

    int letters_appear[NBCHARACTERS] = {0}, index;
    for (int i = 0; i < key_length; i++)
    {
        index = toupper(argv[1][i]) - 'A';
        letters_appear[index]++;
        if (letters_appear[index] == 2)
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    int plaintext_length = strlen(plaintext);
    for (int i = 0; i < plaintext_length; i++)
    {
        if (isalpha(plaintext[i]))
        {
            index = toupper(plaintext[i]) - 'A';
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(argv[1][index]));
            }
            else
            {
                printf("%c", tolower(argv[1][index]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");

    return 0;
}
