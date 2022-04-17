#pragma once

#include <stdbool.h>

typedef struct Item {
	struct Item* previous;
	struct Item* next;
	void* pointer;
} Item;

typedef struct VoidPointerList {
	Item* start;
	Item* end;
	int length;
	int last_accessed_index;
	Item* last_accessed;
} VoidPointerList;

typedef struct List {
	VoidPointerList* (*create)();
	void (*add)(VoidPointerList* list, void* pointer);
	void (*set)(VoidPointerList* list, int position, void* pointer);
	void (*insert)(VoidPointerList* list, int position, void* pointer);
	void (*remove)(VoidPointerList* list, int position);
	void* (*get)(VoidPointerList* list, int position);
	void* (*to_array)(VoidPointerList* list);
	void (*print_connect)(VoidPointerList* list, char* type, char* connect);
	void (*print)(VoidPointerList* list, char* type);
	void (*println)(VoidPointerList* list, char* type);
	bool (*is_empty)(VoidPointerList* list);
	int (*length)(VoidPointerList* list);
	void (*destroy)(VoidPointerList* list);
} List;

extern List list;

void core_list_initialize();
