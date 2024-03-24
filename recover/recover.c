#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *memory_card = fopen("card.raw", "r");
    if (memory_card == NULL)
    {
        return 1;
    }

    // While there's still data left to read from the memory card

        // Create JPEGs from the data

    fclose(memory_card);
}
