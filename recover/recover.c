#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEG_BLOCK_SIZE 512
#define JPEG_OUTPUT_SIZE 8

typedef uint8_t BYTE;

void clean(BYTE *buffer, int size);
int is_jpeg(BYTE *buffer);

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
        printf("File not found.\n");
        return 1;
    }

    // Create a buffer for a block of data
    BYTE buffer[JPEG_BLOCK_SIZE];
    clean(buffer, JPEG_BLOCK_SIZE);
    // For the purpose of generating the file's name
    char file_name[JPEG_OUTPUT_SIZE];
    int i = 0;

    FILE *f = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, JPEG_BLOCK_SIZE, 1, card) == JPEG_BLOCK_SIZE)
    {
        // Verify if it is a JPEG file
        if (is_jpeg(buffer))
        {
            // Create JPEG from the data inside the buffer
            sprintf(file_name, "%3i.jpg", i);
            f = fopen(file_name, "w");
            if (f == NULL)
            {
                printf("Odds are there is no longer spaces in memory to recover images.\n");
                fclose(card);
                return 1;
            }
            fwrite(buffer, JPEG_BLOCK_SIZE, 1, f);
            fclose(f);
            clean(buffer, JPEG_BLOCK_SIZE);
            i++;
        }
    }

    fclose(card);
}

void clean(BYTE *buffer, int size)
{
    for (int i = 0; i < size; i++)
    {
        buffer[i] = (BYTE) 0;
    }
}

int is_jpeg(BYTE *buffer)
{
    if (buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff)
    {
        return 0;
    }

    if (!(0xe0 <= buffer[3] && buffer[3] <= 0xef))
    {
        return 0;
    }

    return 1;
}
