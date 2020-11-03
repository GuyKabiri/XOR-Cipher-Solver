#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

#include "LinkedList.h"

#define HASHTABLE_SIZE 1000

typedef struct hashtable {
	LinkedList table[HASHTABLE_SIZE];
} HashTable;

void init_hashtable(HashTable* ht);
int add_word(HashTable* hs, char* word);
int hash_key(char* word);
int is_exists_hashtable(HashTable* ht, char* word);
void print_hashtable(HashTable* ht);
void free_hashtable(HashTable* ht);

#endif // !__HASHTABLE_H__