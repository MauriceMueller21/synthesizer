#include "char_list.h"

#include "core.h"

#include <stdlib.h>

CharListFunctions char_list_functions;

char core_char_list_get(CharList* list, int position);
int core_char_list_get_length(CharList* list);

CharList* core_char_list_create() {
	List* list = core.list.create();
	CharList* char_list = malloc(sizeof(CharList));
	char_list->list = list;
	return char_list;
}

void core_char_list_add(CharList* list, char character) {
	char* pointer = malloc(sizeof(char));
	*pointer = character;
	core.list.add(list->list, pointer);
}

void core_char_list_push(CharList* list, char character) {
	core_char_list_add(list, character);
}

void core_char_list_set(CharList* list, int position, char character) {
	char* pointer = malloc(sizeof(char));
	*pointer = character;
	core.list.set(list->list, position, pointer);
}

void core_char_list_insert(CharList* list, int position, char character) {
	char* pointer = malloc(sizeof(char));
	*pointer = character;
	core.list.insert(list->list, position, pointer);
}

void core_char_list_remove(CharList* list, int position) {
	core.list.remove(list->list, position);
}

char core_char_list_pop(CharList* list) {
	int length = core_char_list_get_length(list);
	if (length >= 1) {
		char value = core_char_list_get(list, length - 1);
		core_char_list_remove(list, length - 1);
		return value;
	} else {
		return 0;
	}
}

char core_char_list_get(CharList* list, int position) {
	void* pointer = core.list.get(list->list, position);
	return *((char*)pointer);
}

char core_char_list_peek(CharList* list) {
	int length = core_char_list_get_length(list);
	if (length >= 1) {
		return core_char_list_get(list, length - 1);
	} else {
		return 0;
	}
}

void* core_char_list_to_array(CharList* list) {
	return core.list.to_array(list->list);
}

char* core_char_list_to_string(CharList* list) {
	int length = core.list.get_length(list->list);
	char* string = malloc(length + 1);
	int index = 0;
	while (index < length) {
		string[index] = core_char_list_get(list, index);
		index++;
	}
	string[index] = 0;
	return string;
}

void core_char_list_print_connect(CharList* list, char* connect) {
	core.list.print_connect(list->list, "%c", connect);
}

void core_char_list_print(CharList* list) {
	core.list.print(list->list, "%c");
}

void core_char_list_println(CharList* list) {
	core.list.println(list->list, "%c");
}

bool core_char_list_is_empty(CharList* list) {
	return core.list.is_empty(list->list);
}

int core_char_list_get_length(CharList* list) {
	return core.list.get_length(list->list);
}

void core_char_list_destroy(CharList* list) {
	core.list.destroy(list->list);
	free(list);
}

void core_char_list_initialize() {
	char_list_functions.create = &core_char_list_create;
	char_list_functions.add = &core_char_list_add;
	char_list_functions.push = &core_char_list_push;
	char_list_functions.set = &core_char_list_set;
	char_list_functions.insert = &core_char_list_insert;
	char_list_functions.remove = &core_char_list_remove;
	char_list_functions.pop = &core_char_list_pop;
	char_list_functions.get = &core_char_list_get;
	char_list_functions.peek = &core_char_list_peek;
	char_list_functions.to_array = &core_char_list_to_array;
	char_list_functions.to_string = &core_char_list_to_string;
	char_list_functions.print_connect = &core_char_list_print_connect;
	char_list_functions.print = &core_char_list_print;
	char_list_functions.println = &core_char_list_println;
	char_list_functions.is_empty = &core_char_list_is_empty;
	char_list_functions.get_length = &core_char_list_get_length;
	char_list_functions.destroy = &core_char_list_destroy;
}
