#include "string_list.h"

#include "core.h"

#include <stdlib.h>

StringListFunctions string_list_functions;

char* core_string_list_get(StringList* list, int position);
int core_string_list_get_length(StringList* list);

StringList* core_string_list_create() {
	List* list = core.list.create();
	StringList* string_list = malloc(sizeof(StringList));
	string_list->list = list;
	return string_list;
}

void core_string_list_add(StringList* list, char* string) {
	core.list.add(list->list, string);
}

void core_string_list_push(StringList* list, char* string) {
	core_string_list_add(list, string);
}

void core_string_list_set(StringList* list, int position, char* string) {
	core.list.set(list->list, position, string);
}

void core_string_list_insert(StringList* list, int position, char* string) {
	core.list.insert(list->list, position, string);
}

void core_string_list_remove(StringList* list, int position) {
	core.list.remove(list->list, position);
}

char* core_string_list_pop(StringList* list) {
	int length = core_string_list_get_length(list);
	if (length >= 1) {
		char* value = core_string_list_get(list, length - 1);
		core_string_list_remove(list, length - 1);
		return value;
	} else {
		return 0;
	}
}

char* core_string_list_get(StringList* list, int position) {
	void* pointer = core.list.get(list->list, position);
	return (char*)pointer;
}

char* core_string_list_peek(StringList* list) {
	int length = core_string_list_get_length(list);
	if (length >= 1) {
		return core_string_list_get(list, length - 1);
	} else {
		return 0;
	}
}

void* core_string_list_to_array(StringList* list) {
	return core.list.to_array(list->list);
}

void core_string_list_print_connect(StringList* list, char* connect) {
	core.list.print_connect(list->list, "%s", connect);
}

void core_string_list_print(StringList* list) {
	core.list.print(list->list, "%s");
}

void core_string_list_println(StringList* list) {
	core.list.println(list->list, "%s");
}

bool core_string_list_is_empty(StringList* list) {
	return core.list.is_empty(list->list);
}

int core_string_list_get_length(StringList* list) {
	return core.list.get_length(list->list);
}

int core_string_list_get_length_sum(StringList* list) {
	int length = core_string_list_get_length(list);
	int sum = 0;
	int index = 0;
	while (index < length) {
		char* string = core_string_list_get(list, index);
		sum += core.string.get_length(string);
		index++;
	}
	return sum;
}

void core_string_list_destroy(StringList* list) {
	core.list.destroy(list->list);
	free(list);
}

void core_string_list_initialize() {
	string_list_functions.create = &core_string_list_create;
	string_list_functions.add = &core_string_list_add;
	string_list_functions.push = &core_string_list_push;
	string_list_functions.set = &core_string_list_set;
	string_list_functions.insert = &core_string_list_insert;
	string_list_functions.remove = &core_string_list_remove;
	string_list_functions.pop = &core_string_list_pop;
	string_list_functions.get = &core_string_list_get;
	string_list_functions.peek = &core_string_list_peek;
	string_list_functions.to_array = &core_string_list_to_array;
	string_list_functions.print_connect = &core_string_list_print_connect;
	string_list_functions.print = &core_string_list_print;
	string_list_functions.println = &core_string_list_println;
	string_list_functions.is_empty = &core_string_list_is_empty;
	string_list_functions.get_length = &core_string_list_get_length;
	string_list_functions.get_length_sum = &core_string_list_get_length_sum;
	string_list_functions.destroy = &core_string_list_destroy;
}
