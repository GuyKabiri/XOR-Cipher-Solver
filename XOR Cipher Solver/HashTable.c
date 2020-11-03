#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"

void init_hashtable(HashTable* ht)
{
	for (int i = 0; i < HASHTABLE_SIZE; i++)
		init_list(&ht->table[i]);
}

int add_word(HashTable* hs, char* word)
{
	int key = hash_key(word);

	return add_char_node(&hs->table[key], word) ? key : -1;
}

int hash_key(char* word)
{
	int key = 0;
	for (int i = 0; i < strlen(word); i++)
	{
		key += word[i] * 31;
	}
	key %= HASHTABLE_SIZE;
	return key;
}

int is_exists_hashtable(HashTable* ht, char* word)
{
	int key = hash_key(word);
	return is_exists_linkedlist(&ht->table[key], word);
}

void print_hashtable(HashTable* ht)
{
	for (int i = 0; i < HASHTABLE_SIZE; i++)
	{
		if (!is_empty(&ht->table[i]))
		{
			printf("Key = %d ", i);
			print_list(&ht->table[i]);
		}
	}
}

void free_hashtable(HashTable* ht)
{
	for (int i = 0; i < HASHTABLE_SIZE; i++)
		free_list(&ht->table[i]);
}