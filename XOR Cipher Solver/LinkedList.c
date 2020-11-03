#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


void init_list(LinkedList* list)
{
	if (!list)	return;		//	if not allocated

	list->head.next = NULL;
	list->head.value = NULL;
	list->size = 0;
}

//	add at the end of a list a new char node, and return it
Node* add_char_node(LinkedList* list, char* word)
{
	Node* node = init_node(word);					//	allocate a new char node
	return node ? add_node(list, node) : NULL;		//	if allocation was not successful, return NULL

	//if (!node) return NULL;
	//return add(list, node);
}

//	add at the end of the list a node that already allocated, and return it
Node* add_node(LinkedList* list, Node* node)
{
	Node* ptr = &list->head;

	while (has_next(ptr))		//	while ptr is not the last node
		ptr = ptr->next;		//	get the next node

	ptr->next = node;			//	add 'node' after the current last one
	list->size++;
	return ptr->next;			//	return the new last node
}

//	remove a node from the list, and return it
//	DO NOT FREE THE REMOVED NODE
Node* remove_node(LinkedList* list, Node* node)
{
	Node* ptr = &list->head;
	//	the node before the one need to be removed is needed so the actual node could be removed
	while (has_next(ptr) && compare_nodes(ptr->next, node) != 0)	//	while ptr is not the last node, and it's next one is different from the searched node
		ptr = ptr->next;											//	get the next node

	//	at this point ptr points either to the last node in the list or it's next node points to the one that need to be removed
	//	so if ptr is the last node in the list, that's means the searched node does not exists in the list

	if (ptr->next == NULL)	return NULL;							//	if ptr is the last node -> nothing have been removed

	ptr->next = ptr->next->next;									//	reassemble the list without the node
	list->size--;
	return node;													//	return the removed node
}

int is_empty(LinkedList* list)
{
	return list->size == 0;
}

//	checks if a word exists in the linked list
//	if exists return 1, otherwise return 0
int is_exists_linkedlist(LinkedList* list, char* word)
{
	Node find_node;
	init_node(&find_node);
	find_node.value = word;

	Node* ptr = list->head.next;

	while (ptr != NULL && compare_nodes(ptr, &find_node) != 0)
	{
		ptr = ptr->next;
	}

	return ptr != NULL;
}

void print_list(LinkedList* list)
{
	Node* ptr = list->head.next;

	printf("(Size: %d): ", list->size);

	while (ptr != NULL)
	{
		print_node(ptr);
		if (has_next(ptr))	printf(" -> ");
		ptr = ptr->next;
	}
	printf("\n");
}

void free_list(LinkedList* list)
{
	Node* ptr = list->head.next;
	Node* next;

	while (ptr != NULL)
	{
		next = ptr->next;
		free_node(ptr);
		free(ptr);
		ptr = next;
	}
}