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
    else if (digits == 13)
    {
        int one_first = n / (long)pow(10, digits - 1);
        if (one_first == 4)
        {
            valid = true;
            printf("VISA\n");
        }
    }
    else if (digits == 16)
    {
        int one_first = n / (long)pow(10, digits - 1);
        int two_first = n / (long)pow(10, digits - 2);
        if (one_first == 4)
        {
            valid = true;
            printf("VISA\n");
        }
        else
        {
            switch (two_first)
            {
                case 51:
                case 52:
                case 53:
                case 54:
                case 55:
                    valid = true;
                    printf("MASTERCARD\n");
                default:
            }
        }
    }
}
