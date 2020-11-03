#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "main.h"
#include "Solver.h"

void main()
{
	FILE* encrypted_file, * words_file;
	//char encrypted_file_name[CHAR_MAX], words_file_name[CHAR_MAX];
	char* encrypted_file_name = "encrypt.txt";
	char* words_file_name = "words.txt";

	int key_length = 0;
	uchar* file_content = NULL;

	//printf("Please enter the encrypted file name: ");
	//scanf("%s", encrypted_file_name);

	encrypted_file = fopen(encrypted_file_name, "r");
	if (!encrypted_file)
	{
		printf("Can not open file.\n");
		return;
	}

	//printf("What is the key size (number of bits)? ");
	//scanf("%d", &key_length);
	key_length = 8;

	if (key_length < 1)
	{
		printf("Invalid key length.\n");
		fclose(encrypted_file);
		return;
	}

	//printf("Please enter the expected words file name: ");
	//scanf("%s", words_file_name);

	words_file = fopen(words_file_name, "r");
	if (!words_file)
	{
		printf("Can not open file.\n");
		fclose(encrypted_file);
		return;
	}

	fseek(encrypted_file, 0L, SEEK_END);
	int encrypt_file_len = ftell(encrypted_file);
	fseek(encrypted_file, 0, SEEK_SET);

	file_content = malloc(sizeof(uchar) * (encrypt_file_len + 1));
	if (!file_content)
	{
		printf("Error allocate memory.\n");
		fclose(encrypted_file);
		fclose(words_file);
		return;
	}

	if (fread(file_content, sizeof(uchar), encrypt_file_len, encrypted_file) != (encrypt_file_len * sizeof(uchar)))
	{
		printf("Unable to read file.\n");
		fclose(encrypted_file);
		fclose(words_file);
		return;
	}
	file_content[encrypt_file_len] = '\0';

	HashTable ht;
	init_hashtable(&ht);

	read_words(words_file, &ht);

	//printf("Text: %s\n", file_content);

	/*uchar key = 0x9d;
	uchar* text = solve_for_key(file_content, &key, 4);

	uchar* dup_text = _strdup(text);
	free(text);
	text = solve_for_key(dup_text, &key, 4);
	printf("Decrypted: %s\n", text);
	free(text);*/

	uchar* text = "hey guy\0";
	uchar real_key = 0xa << 4;
	uchar* encr = solve_for_key(text, &real_key, 4);
	printf("encrypt: %s\n", encr);
	encr = solve_for_key(encr, &real_key, 4);
	printf("text: %s\n", encr);


	uchar* decr = solve(encr, &ht, 4);
	printf("decrypt: %s\n", decr);

	fclose(encrypted_file);
	fclose(words_file);
	free_hashtable(&ht);
}

HashTable* read_words(FILE* file, HashTable* ht)
{
	if (!file || !ht)		return NULL;

	char word[CHAR_MAX];

	while (!feof(file))
	{
		fscanf(file, "%s", word);
		add_word(ht, word);
	}

	return ht;
}

void main_check_hashtable()
{
	HashTable ht;
	init_hashtable(&ht);

	add_word(&ht, "Guy");
	add_word(&ht, "Guy");
	add_word(&ht, "Kabiri");
	print_hashtable(&ht);
	printf("is 'Guy' exists? %s\n", is_exists_hashtable(&ht, "Guy") ? "Yes" : "No");
	printf("is 'Kabiri' exists? %s\n", is_exists_hashtable(&ht, "Kabiri") ? "Yes" : "No");
	printf("is 'Koala' exists? %s\n", is_exists_hashtable(&ht, "Koala") ? "Yes" : "No");
	printf("is '' exists? %s\n", is_exists_hashtable(&ht, "") ? "Yes" : "No");

	free_hashtable(&ht);
}

void main_check_list_and_node()
{
	LinkedList l;
	init_list(&l);

	add_char_node(&l, "Guy");

	add_char_node(&l, "Node");

	add_char_node(&l, "Three");

	print_list(&l);

	remove_node(&l, l.head.next->next->next);

	print_list(&l);

	free_list(&l);
}