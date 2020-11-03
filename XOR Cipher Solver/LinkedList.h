#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "Node.h"

typedef struct linkedlist {
	Node head;
	int size;
} LinkedList;

void init_list(LinkedList* list);
Node* add_char_node(LinkedList* list, char* word);
Node* add_node(LinkedList* list, Node* node);
Node* remove_node(LinkedList* list, Node* node);
int is_empty(LinkedList* list);
int is_exists_linkedlist(LinkedList* list, char* word);
void print_list(LinkedList* list);
void free_list(LinkedList* list);

#endif // !__LINKEDLIST_H__