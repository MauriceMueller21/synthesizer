#pragma once

#include "list.h"

#include <stdbool.h>

typedef struct CharList {
	List* list;
} CharList;

typedef struct CharListFunctions {
	CharList* (*create)();
	void (*add)(CharList* list, char character);
	void (*push)(CharList* list, char character);
	void (*set)(CharList* list, int position, char character);
	void (*insert)(CharList* list, int position, char character);
	void (*remove)(CharList* list, int position);
	char (*pop)(CharList* list);
	char (*get)(CharList* list, int position);
	char (*peek)(CharList* list);
	void* (*to_array)(CharList* list);
	char* (*to_string)(CharList* list);
	void (*print_connect)(CharList* list, char* connect);
	void (*print)(CharList* list);
	void (*println)(CharList* list);
	bool (*is_empty)(CharList* list);
	int (*get_length)(CharList* list);
	void (*destroy)(CharList* list);
} CharListFunctions;

extern CharListFunctions char_list_functions;

void core_char_list_initialize();
