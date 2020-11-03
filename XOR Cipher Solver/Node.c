#pragma warning(suppress : 4996)
#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Node.h"

Node* init_node(char* word)
{
	Node* node = malloc(sizeof(Node));
	if (!node)	return NULL;
	node->next = NULL;
	node->value = _strdup(word);
	if (!node->value)
	{
		free(node);
		return NULL;
	}
	return node;
}

int has_next(Node* node)
{
	return node->next != NULL;
}

int compare_nodes(const void* p1, const void* p2)
{
	Node* n1 = (Node*)p1;
	Node* n2 = (Node*)p2;

	return strcmp(n1->value, n2->value);
}

void print_node(Node* node)
{
	printf("%s", node->value);
}

void free_node(Node* node)
{
	free(node->value);
}