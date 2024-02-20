#include <cs50.h>
#include <stdio.h>

int number_of_digits(long n);
int sum_of_digits(int n);
void print_type_of_card(long n);
int checksum(long n);

int main(void)
{
    int number = get_long("Number: ");
    int digits = number_of_digits(number);

    print_type_of_card(number);
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

int sum_of_digits(int n)
{
    int sum = 0;

    do
    {
        sum += (n % 10);
        n /= 10;
    }
    while (n != 0);

    return sum;
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
                    break;
                default:
            }
        }
    }

    if (!valid)
        printf("INVALID\n");
}

int checksum(long n)
{
    bool valid = false;
    int m, s,digits = number_of_digits(n);

    m = n;
    do
    {
        f
    }
    while (m != 0);
    sum_of_digits(n)
}
