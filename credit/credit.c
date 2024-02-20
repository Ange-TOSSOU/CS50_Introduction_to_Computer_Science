#include <cs50.h>
#include <stdio.h>

int number_of_digits(long n);

int main(void)
{
    int number = get_long("Number: ");

    int 
}

int number_of_digits(long n)
{
    int digits = 0;

    do
    {
        ++digits;
        n /= 10;
    }
    while (n != 0);

    return digits;
}
