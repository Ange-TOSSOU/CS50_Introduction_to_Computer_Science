#include <cs50.h>
#include <stdio.h>

int number_of_digits(long n);
int sum_of_digits(int n);
long pow_10(int n);
void print_type_of_card(long n);
bool checksum(long n);

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

long pow_10(int n)
{
    long p = 1;

    while (n != 0)
    {
        p *= 10;
        --n;
    }

    return p;
}

void print_type_of_card(long n)
{
    bool valid = false;
    int digits = number_of_digits(n);

    if (digits == 15)
    {
        int two_first = n / pow_10(digits - 2);
        if (two_first == 34 || two_first == 37)
        {
            valid = true;
            //valid = checksum(n);
            if (valid)
                printf("AMEX\n");
        }
    }
    else if (digits == 13)
    {
        int one_first = n / pow_10(digits - 1);
        if (one_first == 4)
        {
            valid = true;
            //valid = checksum(n);
            if (valid)
                printf("VISA\n");
        }
    }
    else if (digits == 16)
    {
        int one_first = n / pow_10(digits - 1);
        int two_first = n / pow_10(digits - 2);
        if (one_first == 4)
        {
            valid = true;
            //valid = checksum(n);
            if (valid)
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
                    valid = checksum(n);
                    if (valid)
                        printf("MASTERCARD\n");
                    break;
                default:
                    ;
            }
        }
    }

    if (!valid)
        printf("INVALID\n");
}

bool checksum(long n)
{
    int digits = number_of_digits(n);
    int s = 0;

    do
    {
        s += n % 10;
        n /= 10;
        s += sum_of_digits(2 * (n % 10));
        n /= 10;
    }
    while (n != 0);

    if (s % 10 == 0)
        return true;

    return false;
}
