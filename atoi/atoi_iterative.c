#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    // Check if user's input consists only of digit character(s)
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        // Check if input[i] is a digit character
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int number = 0, base_product = 1;

    for (int i = strlen(input) - 1; i >= 0; i--)
    {
        number += base_product * (input[i] - '0');
        base_product *= 10;
    }

    return number;
}
