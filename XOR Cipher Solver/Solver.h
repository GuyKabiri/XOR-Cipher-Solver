#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "HashTable.h"

int solve(char* encrypted, HashTable* words, int key_length);
char* solve_for_key(char* encrypted, char* key);

#endif // !__SOLVER_H__