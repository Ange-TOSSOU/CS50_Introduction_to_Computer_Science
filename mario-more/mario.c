#include <cs50.h>
#include <stdio.h>

void print_left(int h, int n);
void print_middle(void);
void print_right(int h, int n);

int main(void)
{
    int height = 0;
    do {
        height = get_int("Height: ");
    }while(height < 1 || height > 8);
}

void print_left(int h, int n)
{
    for (int i = 0; i < h-n; i++)
        printf(" ");

    for (int i = 0; i < n; i++)
        printf("#");
}

void print_middle(void);

void print_right(int n)
{
    for (int i = 0; i < n; i++)
        printf("#");
}
