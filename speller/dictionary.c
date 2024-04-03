// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

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
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int sum_ascii = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        sum_ascii += word[i];
    }

    return sum_ascii;
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

    char *word[LENGTH + 2];
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

        //Hash the word to obtain its hash value
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
    return false;
}
