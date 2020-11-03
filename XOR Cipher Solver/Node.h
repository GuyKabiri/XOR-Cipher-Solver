#ifndef __NODE_H__
#define __NODE_H__

typedef struct node {
	char* value;
	struct node* next;
} Node;

Node* init_node(char* word);
int has_next(Node* node);
int compare_nodes(const void* p1, const void* p2);
void print_node(Node* node);
void free_node(Node* node);

#endif // !__NODE_H__