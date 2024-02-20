#include <cs50.h>
#include <stdio.h>

int number_of_digits(long n);
void print_type_of_card(long n);

int main(void)
{
    int number = get_long("Number: ");
    int digits = number_of_digits(number);


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

void print_type_of_card(long n)
{
    bool valid = false;
    int digits = number_of_digits(n);

    if (digits == 15)
    {
        int two_first = n / (long)pow(10, digits - 2);
        if (two_first == 34 || two_first == 37)
        {
            valid = true;
            printf("AMEX\n");
        }
    }
    else if (digits == 15)
}
