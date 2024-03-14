#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int convert_service(string input, int base_product);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
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
    return convert_service(input, 1);
}

int convert_service(string input, int base_product)
{
    int last_char_index = strlen(input) - 1;

    if (last_char_index < 0)
        return 0;

    int n = base_product * (input[last_char_index] - '0');
    input[last_char_index] = '\0';
    return n + convert_service(input, base_product * 10);
}
