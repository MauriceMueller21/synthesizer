#pragma once

#include <stdbool.h>

typedef struct ListItem {
	struct ListItem* previous;
	struct ListItem* next;
	void* pointer;
} ListItem;

typedef struct List {
	ListItem* start;
	ListItem* end;
	int length;
	int last_accessed_index;
	ListItem* last_accessed;
} List;

typedef struct ListFunctions {
	List* (*create)();
	void (*add)(List* list, void* pointer);
	void (*push)(List* list, void* pointer);
	void (*set)(List* list, int position, void* pointer);
	void (*insert)(List* list, int position, void* pointer);
	void (*remove)(List* list, int position);
	void* (*pop)(List* list);
	void* (*get_item)(List* list, int position);
	void* (*get)(List* list, int position);
	void* (*peek)(List* list);
	void* (*to_array)(List* list);
	void (*print_connect)(List* list, char* type, char* connect);
	void (*print)(List* list, char* type);
	void (*println)(List* list, char* type);
	bool (*is_empty)(List* list);
	int (*get_length)(List* list);
	void (*destroy)(List* list);
} ListFunctions;

extern ListFunctions list_functions;

void core_list_initialize();
