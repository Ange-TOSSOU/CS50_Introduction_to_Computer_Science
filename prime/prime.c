#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    // Get the minimum. It must be a non-positive integer.
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Get the maximum. It must be an integer greater than the minimum.
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);


    if (min <= 2)
    {
        printf("2\n");
    }
    for (int i = min / 2; 2 * i + 1 <= max; i++)
    {
        if (prime(2 * i + 1))
        {
            printf("%i\n", 2 * i + 1);
        }
    }
}

bool prime(int number)
{
    // TODO
    if (number < 2)
        return false;

    for (int i = 2; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}
