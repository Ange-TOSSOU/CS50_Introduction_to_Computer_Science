#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase "
               "letter, number and symbol\n");
    }
}

bool valid(string password)
{
    // Return true if the password has at least one lowercase letter, uppercase
    // letter, number and symbol and Return false if not
    bool is_lower_case_letter_exist = false;
    bool is_upper_case_letter_exist = false;
    bool is_number_exist = false;
    bool is_symbol_exist = false;

    int password_length = strlen(password);

    for (int i = 0; i < password_length; i++)
    {
        if (islower(password[i]))
        {
            is_lower_case_letter_exist = true;
        }
        else if (isupper(password[i]))
        {
            is_upper_case_letter_exist = true;
        }
        else if (isdigit(password[i]))
        {
            is_number_exist = true;
        }
        else
        {
            if (!isblank(password[i]))
            {
                is_symbol_exist = true;
            }
        }

        if (is_lower_case_letter_exist && is_upper_case_letter_exist &&
            is_number_exist && is_symbol_exist)
        {
            return true;
        }
    }

    return false;
}
