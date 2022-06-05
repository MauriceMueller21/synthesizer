#pragma once

#include "list.h"

#include <stdbool.h>

typedef struct StringList {
	List* list;
} StringList;

typedef struct StringListFunctions {
	StringList* (*create)();
	void (*add)(StringList* list, char* string);
	void (*push)(StringList* list, char* string);
	void (*set)(StringList* list, int position, char* string);
	void (*insert)(StringList* list, int position, char* string);
	void (*remove)(StringList* list, int position);
	char* (*pop)(StringList* list);
	char* (*get)(StringList* list, int position);
	char* (*peek)(StringList* list);
	void* (*to_array)(StringList* list);
	void (*print_connect)(StringList* list, char* connect);
	void (*print)(StringList* list);
	void (*println)(StringList* list);
	bool (*is_empty)(StringList* list);
	int (*get_length)(StringList* list);
	int (*get_length_sum)(StringList* list);
	void (*destroy)(StringList* list);
} StringListFunctions;

extern StringListFunctions string_list_functions;

void core_string_list_initialize();
