#ifndef __SOLVER_H__
#define __SOLVER_H__

#include "HashTable.h"

typedef unsigned char uchar;
typedef unsigned int uint;

uchar* solve(uchar* encrypted, HashTable* words, int key_length);
uchar* solve_for_key(uchar* encrypted, uchar* key, int key_len);
int is_real_text(uchar* decrypted, HashTable* words);

#endif // !__SOLVER_H__
