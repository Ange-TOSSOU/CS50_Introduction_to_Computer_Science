#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEG_BLOCK_SIZE 512
#define JPEG_OUTPUT_SIZE 8

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
    // For the purpose of generating the file's name
    char *file_name[JPEG_OUTPUT_SIZE];
    int i = 0;

    FILE *f = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, 1, JPEG_BLOCK_SIZE, card) == JPEG_BLOCK_SIZE)
    {
        // Create JPEGs from the data
        sprintf(file_name, "%3i.jpg", i);
        f = fopen(file_name, "w");
        if (f == NULL)
        {
            printf("Odds are there is no longer spaces in memory to recover images.");
            fclose(card);
            return 1;
        }
        fwrite(buffer, 1, JPEG_BLOCK_SIZE, f);
        fclose(f);
    }

    fclose(memory_card);
}
