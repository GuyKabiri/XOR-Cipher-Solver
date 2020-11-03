#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"


void init_list(LinkedList* list)
{
	if (!list)	return;

	list->head.next = NULL;
	list->head.value = NULL;
	list->size = 0;
}

Node* add_char_node(LinkedList* list, char* word)
{
	Node* node = init_node(word);
	return node ? add_node(list, node) : NULL;

	//if (!node) return NULL;
	//return add(list, node);
}

Node* add_node(LinkedList* list, Node* node)
{
	Node* ptr = &list->head;

	while (has_next(ptr))
		ptr = ptr->next;

	ptr->next = node;
	list->size++;
	return ptr->next;
}

Node* remove_node(LinkedList* list, Node* node)
{
	Node* ptr = &list->head;

	while (has_next(ptr) && compare_nodes(ptr->next, node) != 0)
		ptr = ptr->next;

	if (ptr->next == NULL)	return NULL;

	ptr->next = ptr->next->next;
	list->size--;
	return node;
}

int is_empty(LinkedList* list)
{
	return list->size == 0;
}

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