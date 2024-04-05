// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// The size of the dictionary loaded
int size_dic = 0;

// TODO: Choose number of buckets in hash table
const unsigned int N = 2600;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // Hash the word to obtain its hash value
    int index = hash(word);

    // Search
    node *cur = table[index];
    while (cur != NULL)
    {
        if (strcasecmp(word, cur->word) == 0)
        {
            return true;
        }

        if (cur->word[0] < tolower[0])
        {
            break;
        }

        // Continue to search the word
        cur = cur->next;
    }

    // Word not found
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum_ascii = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum_ascii += tolower(word[i]);
    }

    return sum_ascii % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    size_dic = 0;
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        return false;
    }

    char word[LENGTH + 2];
    node *n = NULL;
    int index;
    // Read each word in the file
    while (fgets(word, LENGTH + 2, source))
    {
        // Consume the '\n' character
        word[strlen(word) - 1] = '\0';

        // Create space for a new hash table node
        n = malloc(sizeof(node));
        if (n == NULL)
        {
            fclose(source);
            unload();
            size_dic = 0;
            return false;
        }

        // Copy the word into the new node
        strcpy(n->word, word);

        // Add each word to the hash table

        // Hash the word to obtain its hash value
        index = hash(word);

        // Insert the new node into the hash table
        n->next = table[index];
        table[index] = n;

        size_dic++;
    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return size_dic;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node *tmp = NULL;
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            tmp = table[i];
            table[i] = table[i]->next;
            free(tmp);
        }
    }

    return true;
}
