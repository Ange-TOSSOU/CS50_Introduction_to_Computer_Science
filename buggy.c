#include <stdio.h>

int main(void)
{
    print_column();
}

void print_column(int height)
{
    for (int i = 0; i <= height; i++)
    {
        printf("#\n");
    }
}
