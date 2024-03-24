#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEG_BLOCK_SIZE 512

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        return 1;
    }

    // Create a buffer for a block of data
    uint8_t buffer[JPEG_BLOCK_SIZE];

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, JPEG_BLOCK_SIZE, card) == JPEG_BLOCK_SIZE)
    {
        // Create JPEGs from the data

    }

    fclose(memory_card);
}
