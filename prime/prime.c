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
    // Iterate through odd numbers between min(inclusive) and max(inclusive).
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
    // All prime numbers are greater than 1.
    if (number < 2)
        return false;

    // Iterate through integers between 1(exclusive) and sqrt(number)(inclusive).
    for (int i = 2; i * i <= number; ++i)
    {
        // Check if it divide number
        if (number % i == 0)
        {
            return false;
        }
    }

    // There is no divisor other than 1 and the number itself
    return true;
}
