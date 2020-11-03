#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Solver.h"
#include "HashTable.h"

uchar* solve(uchar* encrypted, HashTable* words, int key_length)
{

	int byte_num = key_length / CHAR_BIT;			//	how many chars is needed to store a key with key_length bits
	if (byte_num % CHAR_BIT != 0)
		byte_num++;
	char* key = calloc(byte_num, sizeof(char));
	if (!key)
		return -1;

	uchar* decrypted = NULL;

	int iteration_num = pow(2, key_length);
	for (int i = 0; i < iteration_num; i++)
	{
		*key = (uint)(i << (key_length % CHAR_BIT));			//	assign the next key and shift it to the left-most digit
		decrypted = solve_for_key(encrypted, key, key_length);

		if (is_real_text(decrypted, words))			//	if the decrypted text is actual words
			break;
	}

	return decrypted;
}

uchar* solve_for_key(uchar* encrypted, uchar* key, int key_len)
{
	if (!encrypted || !key || key_len < 2)
		return NULL;

	int text_len = strlen(encrypted);

	uchar* decrypted = calloc(text_len + 1, sizeof(uchar));
	if (!decrypted)
		return	NULL;

	uchar* pCurrChar = encrypted;
	uchar* pCurrDecrypt = decrypted;
	int key_index = 0;

	while (*pCurrChar)	//	while current character is not '\0', iterate over each character
	{
		*pCurrDecrypt = (*pCurrChar) ^ key[key_index % key_len];
 		key_index++;
		pCurrChar++;
		pCurrDecrypt++;
	}

	*(decrypted + text_len) = '\0';
	return decrypted;
}

int is_real_text(uchar* decrypted, HashTable* words)
{
	return 0;
}