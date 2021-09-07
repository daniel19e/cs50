// Implements a dictionary's functionality
#include <strings.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

int count = 0;

// Number of buckets in hash table
const unsigned int N = 1;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int key = hash(word);

    node *node_ptr = table[key];

    while (node_ptr)
    {
        if (strcasecmp(node_ptr->word, word) == 0)
        {
            return true;
        }
        node_ptr = node_ptr->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int value = 0;

    for (int i = 0, len = strlen(word); i < len; i++)
    {
        value += tolower(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    char temp[LENGTH + 1];

    while (fscanf(file, "%s\n", temp) != EOF)
    {
        node *temp_node = malloc(sizeof(node));
        strcpy(temp_node->word, temp);
        int key = hash(temp);

        if (!table[key])
        {
            temp_node->next = NULL;
            table[key] = temp_node;
        }
        else
        {
             temp_node->next = table[key];
             table[key] = temp_node;
        }
        count++;
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *node_ptr = table[i];

        while (node_ptr)
        {
            node *delete_ptr = node_ptr;
            node_ptr = node_ptr->next;
            free(delete_ptr);
        }
        table[i] = NULL;
    }
    return true;
}
