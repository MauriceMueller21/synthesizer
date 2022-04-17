#include "list.h"

#include "core.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

List list;

VoidPointerList* core_list_create() {
	VoidPointerList* list = malloc(sizeof(VoidPointerList));
	list->start = NULL;
	list->end = NULL;
	list->length = 0;
	list->last_accessed_index = 0;
	list->last_accessed = NULL;
	return list;
}

void core_list_add(VoidPointerList* list, void* pointer) {
	Item* item = malloc(sizeof(Item));
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

int core_list_get_optimal_pointer(VoidPointerList* list, int interest) {
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

void core_list_move_last_accessed(VoidPointerList* list, int position) {
	if (list->length == 0 || position == list->last_accessed_index) {
		return;
	}
	int score = core_list_get_optimal_pointer(list, position);
	int index;
	Item* item = NULL;
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

void core_list_set(VoidPointerList* list, int position, void* pointer) {
	core_list_move_last_accessed(list, position);
	list->last_accessed->pointer = pointer;
}

void core_list_insert(VoidPointerList* list, int position, void* pointer) {
	if (list->length == 0 || position == list->length) {
		core_list_add(list, pointer);
	} else if (position == 0) {
		Item* item = malloc(sizeof(Item));
		item->pointer = pointer;
		item->previous = NULL;
		item->next = list->start;
		list->start->previous = item;
		list->start = item;
		list->length++;
	} else if (list->length > 0 && position > 0 && position < list->length) {
		core_list_move_last_accessed(list, position);
		Item* item = malloc(sizeof(Item));
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

void core_list_remove(VoidPointerList* list, int position) {
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

void* core_list_get(VoidPointerList* list, int position) {
	core_list_move_last_accessed(list, position);
	return list->last_accessed;
}

void* core_list_to_array(VoidPointerList* list) {
	int length = list->length;
	void** array = malloc(sizeof(void*) * length);
	if (length > 1) {
		Item* item = list->start;
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

void core_list_print_connect(VoidPointerList* list, char* type, char* connect) {
	char* pattern = core.string.concatenate_strings(type, connect);
	if (list->length > 1) {
		Item* item = list->start;
		while (item != list->end) {
			printf(pattern, *(int*)(item->pointer));
			item = item->next;
		}
	}
	if (list->length > 0) {
		printf(type, *(int*)(list->end->pointer));
	}
}

void core_list_print(VoidPointerList* list, char* type) {
	core_list_print_connect(list, type, ", ");
}

void core_list_println(VoidPointerList* list, char* type) {
	core_list_print_connect(list, type, "\n");
}

bool core_list_is_empty(VoidPointerList* list) {
	return list->length == 0;
}

int core_list_length(VoidPointerList* list) {
	return list->length;
}

void core_list_destroy(VoidPointerList* list) {
	if (list->length >= 2) {
		Item* item = list->start;
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
	list.create = &core_list_create;
	list.add = &core_list_add;
	list.set = &core_list_set;
	list.insert = &core_list_insert;
	list.remove = &core_list_remove;
	list.get = &core_list_get;
	list.to_array = &core_list_to_array;
	list.print_connect = &core_list_print_connect;
	list.print = &core_list_print;
	list.println = &core_list_println;
	list.is_empty = &core_list_is_empty;
	list.length = &core_list_length;
	list.destroy = &core_list_destroy;
}
