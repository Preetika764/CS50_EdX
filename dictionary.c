// Implements a dictionary's functionality

#include <stdbool.h>
#include <ctype.h>
#include "dictionary.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    unsigned int index;
    index = hash(word);

    node *p;
    p = table[index];
    while(p!=NULL)
    {
        if(strcasecmp(p->word,word)==0)
            {
                return true;
            }
        p = p->next;

    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int x = toupper(word[0]);
    return (x % 65);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    char word[LENGTH + 1];
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new = malloc(sizeof(node));
        if (new == NULL)
        {
        return false;
        }
        strcpy(new->word, word);
        new->next = NULL;
        int x = hash(word);
        new->next = table[x];
        table[x] = new;

    }

    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    unsigned int ctr = 0;
    node *p = NULL;
    for (int i = 0; i < N; i++)
    {
        p = table[i];
        if (p == NULL)
        {
            continue;
        }
        while (p != NULL)
        {
            ctr++;
            p = p->next;
        }

    }
    return ctr;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node *p, *q;
    for (int i = 0; i < N; i++)
    {
    p = table[i];
    while (p != NULL)
    {
    q = p;
    p = p->next;
    free(q);
    }
    }
    return true;
}
