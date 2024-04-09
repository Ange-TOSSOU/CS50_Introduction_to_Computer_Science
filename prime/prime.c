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

    // All prime numbers are odd except 2.
    if (min <= 2)
    {
        printf("2\n");
    }
    // Iterate through odd numbers which do not exceed max.
    for (int i = min / 2; 2 * i + 1 <= max; i++)
    {
        // Check if it's prime
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
