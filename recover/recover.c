#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define JPEG_BLOCK_SIZE 512
#define JPEG_OUTPUT_SIZE 8

typedef uint8_t BYTE;

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
    // For the purpose of generating the file's name
    char file_name[JPEG_OUTPUT_SIZE];
    int i = 0;

    FILE *f = NULL;
    // While there's still data left to read from the memory card
    while (fread(buffer, sizeof(BYTE), JPEG_BLOCK_SIZE, card) == sizeof(BYTE) * JPEG_BLOCK_SIZE)
    {
        // Verify if it is probably a beginning of a JPEG file
        if (is_jpeg(buffer))
        {
            // Close an existing opened JPEG file
            if (f != NULL)
            {
                fclose(f);
            }
            // Create a new JPEG file
            sprintf(file_name, "%03i.jpg", i++);
            f = fopen(file_name, "w");
            if (f == NULL)
            {
                printf("Odds are there is no longer spaces in memory to recover images.\n");
                fclose(card);
                return 2;
            }
            // Set the header of the JPEG file
            fwrite(buffer, sizeof(BYTE), JPEG_BLOCK_SIZE, f);
        }
        else
        {
            // Keep writing in the JPEG file
            if (f != NULL)
            {
                fwrite(buffer, sizeof(BYTE), JPEG_BLOCK_SIZE, f);
            }
        }
    }
    if (i != 0)
    {
        // Close the last file opened
        fclose(f);
    }

    fclose(card);
}

int is_jpeg(BYTE *buffer)
{
    if (buffer[0] != 0xff || buffer[1] != 0xd8 || buffer[2] != 0xff)
    {
        return 0;
    }

    if ((buffer[3] & 0xf0) != 0xe0)
    {
        return 0;
    }

    return 1;
}
