#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "HashTable.h"

typedef unsigned char uchar;

uchar* solve(uchar* encrypted, HashTable* words, int key_length);
uchar* solve_for_key(uchar* encrypted, uchar* key, int key_len);


//char* encrypt(char* text, char* key);

#endif // !__SOLVER_H__
