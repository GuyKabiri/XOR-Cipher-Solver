#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "HashTable.h"

void init_hashtable(HashTable* ht)
{
	for (int i = 0; i < HASHTABLE_SIZE; i++)	//	iterate over the array and initiate every linked list
		init_list(&ht->table[i]);
}

//	add a new word to the table
//	return the key of the word if added, otherwise return -1
int add_word(HashTable* hs, char* word)
{
	int key = hash_key(word);									//	get the hash key of a word
	return add_char_node(&hs->table[key], word) ? key : -1;		//	add the word to the table, and return the key of the word if add, otherwise return -1
}

//	generate hash key for a word
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

//	check if a word exists in the table
//	return 1 if exists, otherwise 0
int is_exists_hashtable(HashTable* ht, char* word)
{
	int key = hash_key(word);								//	generate a hash key for the word
	return is_exists_linkedlist(&ht->table[key], word);		//	checks if the word exists in that linked list
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