#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string replace(string word);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    replace(argv[1]);

    printf("%s\n", argv[1]);

    return 0;
}

string replace(string word)
{
    // Replace vowels with numbers
    int length_word = strlen(word);

    for (int i = 0; i < length_word; i++)
    {
        switch (tolower(word[i]))
        {
            case 'a':
                word[i] = '6';
                break;
            case 'e':
                word[i] = '3';
                break;
            case 'i':
                word[i] = '1';
                break;
            case 'o':
                word[i] = '0';
                break;
            default:;
        }
    }

    return word;
}
