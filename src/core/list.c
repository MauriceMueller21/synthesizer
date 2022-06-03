#include "list.h"

#include "core.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

ListFunctions list_functions;

void* core_list_get(List* list, int position);
int core_list_get_length(List* list);

List* core_list_create() {
	List* list = malloc(sizeof(List));
	list->start = NULL;
	list->end = NULL;
	list->length = 0;
	list->last_accessed_index = 0;
	list->last_accessed = NULL;
	return list;
}

void core_list_add(List* list, void* pointer) {
	ListItem* item = malloc(sizeof(ListItem));
	item->pointer = pointer;
	item->previous = NULL;
	item->next = NULL;
	if (list->length == 0) {
		list->start = item;
		list->last_accessed_index = 0;
		list->last_accessed = list->start;
	} else {
		list->end->next = item;
		item->previous = list->end;
	}
	list->end = item;
	list->length++;
}

void core_list_push(List* list, void* pointer) {
	core_list_add(list, pointer);
}

int core_list_get_optimal_pointer(List* list, int interest) {
	int last = list->last_accessed_index;
	int to_start = interest;
	int to_last = interest > last ? interest - last : last - interest;
	int to_end = list->length - interest;
	if (to_start > to_last && to_start > to_end) {
		return 0;
	} else if (to_last > to_end) {
		return 1;
	} else {
		return 2;
	}
}

void core_list_move_last_accessed(List* list, int position) {
	if (list->length == 0 || position == list->last_accessed_index) {
		return;
	}
	int score = core_list_get_optimal_pointer(list, position);
	int index;
	ListItem* item = NULL;
	if (score == 0) {
		index = 0;
		item = list->start;
	} else if (score == 1) {
		index = list->last_accessed_index;
		item = list->last_accessed;
	} else if (score == 2) {
		index = list->length - 1;
		item = list->end;
	}
	while (index != position) {
		if (index < position) {
			index++;
			item = item->next;
		} else {
			index--;
			item = item->previous;
		}
	}
	list->last_accessed_index = index;
	list->last_accessed = item;
}

void core_list_set(List* list, int position, void* pointer) {
	core_list_move_last_accessed(list, position);
	list->last_accessed->pointer = pointer;
}

void core_list_insert(List* list, int position, void* pointer) {
	if (list->length == 0 || position == list->length) {
		core_list_add(list, pointer);
	} else if (position == 0) {
		ListItem* item = malloc(sizeof(ListItem));
		item->pointer = pointer;
		item->previous = NULL;
		item->next = list->start;
		list->start->previous = item;
		list->start = item;
		list->length++;
	} else if (list->length > 0 && position > 0 && position < list->length) {
		core_list_move_last_accessed(list, position);
		ListItem* item = malloc(sizeof(ListItem));
		item->pointer = pointer;
		item->next = list->last_accessed;
		item->previous = list->last_accessed->previous;
		list->last_accessed->previous->next = item;
		list->last_accessed->previous = item;
		list->last_accessed = item;
		list->length++;
	} else {
		printf("WARNING: index %d is out of list with length %d!\n", position, list->length);
	}
}

void core_list_remove(List* list, int position) {
	if (list->length == 0 || position < 0 || position >= list->length) {
		printf("WARNING: index %d is out of list with length %d!\n", position, list->length);
		return;
	}
	core_list_move_last_accessed(list, position);
	if (list->length == 1) {
		free(list->start);
		list->length = 0;
		list->start = NULL;
		list->last_accessed = NULL;
		list->last_accessed_index = 0;
		list->end = NULL;
		return;
	}
	// Here the length is always >= 2
	// If the index == 0, there is always a next element
	// If the index is length - 1, there is always a previous element
	// Otherwise, the list length is > 2 and there is always a previous and a
	// next element
	if (position == 0) {
		list->start = list->start->next;
		list->start->previous = NULL;
		list->last_accessed = list->start;
	} else if (position == list->length - 1) {
		list->end = list->end->previous;
		list->end->next = NULL;
		list->last_accessed = list->end;
		list->last_accessed_index--;
	} else {
		list->last_accessed->next->previous = list->last_accessed->previous;
		list->last_accessed->previous->next = list->last_accessed->next;
		list->last_accessed = list->last_accessed->next;
	}
	list->length--;
}

void* core_list_pop(List* list) {
	int length = core_list_get_length(list);
	if (length >= 1) {
		void* value = core_list_get(list, length - 1);
		core_list_remove(list, length - 1);
		return value;
	} else {
		return 0;
	}
}

void* core_list_get_item(List* list, int position) {
	core_list_move_last_accessed(list, position);
	return list->last_accessed;
}

void* core_list_get(List* list, int position) {
	ListItem* item = core_list_get_item(list, position);
	return item->pointer;
}

void* core_list_peek(List* list) {
	int length = core_list_get_length(list);
	if (length >= 1) {
		return core_list_get(list, length - 1);
	} else {
		return 0;
	}
}

void* core_list_to_array(List* list) {
	int length = list->length;
	void** array = malloc(sizeof(void*) * length);
	if (length > 1) {
		ListItem* item = list->start;
		int index = 0;
		while (index < length) {
			array[index] = (int*)(item->pointer);
			item = item->next;
			index++;
		}
	}
	if (length > 0) {
		array[length - 1] = (int*)(list->end->pointer);
	}
	return array;
}

void core_list_print_connect(List* list, char* type, char* connect) {
	char* pattern = core.string.concatenate_strings(type, connect);
	if (list->length > 1) {
		ListItem* item = list->start;
		while (item != list->end) {
			printf(pattern, *(int*)(item->pointer));
			item = item->next;
		}
	}
	if (list->length > 0) {
		printf(type, *(int*)(list->end->pointer));
	}
}

void core_list_print(List* list, char* type) {
	core_list_print_connect(list, type, ", ");
}

void core_list_println(List* list, char* type) {
	core_list_print_connect(list, type, "\n");
}

bool core_list_is_empty(List* list) {
	return list->length == 0;
}

int core_list_get_length(List* list) {
	return list->length;
}

void core_list_destroy(List* list) {
	if (list->length >= 2) {
		ListItem* item = list->start;
		while (item != list->end) {
			item = item->next;
			free(item->previous);
		}
	}
	if (list->length > 0) {
		free(list->end);
	}
	free(list);
}

void core_list_initialize() {
	list_functions.create = &core_list_create;
	list_functions.add = &core_list_add;
	list_functions.push = &core_list_push;
	list_functions.set = &core_list_set;
	list_functions.insert = &core_list_insert;
	list_functions.remove = &core_list_remove;
	list_functions.pop = &core_list_pop;
	list_functions.get_item = &core_list_get_item;
	list_functions.get = &core_list_get;
	list_functions.peek = &core_list_peek;
	list_functions.to_array = &core_list_to_array;
	list_functions.print_connect = &core_list_print_connect;
	list_functions.print = &core_list_print;
	list_functions.println = &core_list_println;
	list_functions.is_empty = &core_list_is_empty;
	list_functions.get_length = &core_list_get_length;
	list_functions.destroy = &core_list_destroy;
}
