#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clean_memory(char *plates[], int size);

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];

    // Try to open the file
    FILE *infile = fopen(argv[1], "r");
    if (infile == NULL)
    {
        printf("Unable to open the file.\n");
        return 1;
    }

    // Allocate memory to store each plate number
    for (int i = 0; i < 8; i++)
    {
        plates[i] = malloc(7 * sizeof(char));
        if (plates[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            // Clean memory for all previous allocations
            clean_memory(plates, i);
        }
    }

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        strcpy(plates[idx], buffer);
        idx++;
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }

    clean_memory(plates, 8);
    fclose(infile);
}

void clean_memory(char *plates[], int size)
{
    for (int i = 0; i < size; i++)
    {
        free(plates[i]);
    }
}
