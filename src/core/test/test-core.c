#include "../core.h"

#include <stdio.h>

int test_list();
void show_list(List* list);
void show_cursor(List* list);
int test_char_list();
int test_string_list();
int test_string();

#ifdef CORETEST

int main(int argc, char** argv) {
	core_initialize();
	int success_list = test_list();
	int success_char_list = test_char_list();
	int success_string_list = test_string_list();
	int success_string = test_string();
	printf("Executed core test successfully (%d parameters, %p is the pointer).\n", argc, argv);
	printf("Tested core.list successfully: %d\n", success_list);
	printf("Tested core.charlist successfully: %d\n", success_char_list);
	printf("Tested core.stringlist successfully: %d\n", success_string_list);
	printf("Tested core.string successfully: %d\n", success_string);
	int success = success_list && success_char_list && success_string_list && success_string;
	return !success;// successful/true = return code 0
}

#endif

int test_list() {
	List* list = core.list.create();
	printf("Address of list: %p\n", list);
	printf("Is the list empty? %s\n", core.string.boolean_to_string(core.list.is_empty(list)));
	char a = 'a';
	char b = 'b';
	char c = 'c';
	char d = 'd';
	char e = 'e';
	char f = 'f';
	char* ap = &a;
	char* bp = &b;
	char* cp = &c;
	char* dp = &d;
	char* ep = &e;
	char* fp = &f;
	printf("char pointer to a: %p\n", ap);
	printf("char pointer to b: %p\n", bp);
	printf("char pointer to c: %p\n", cp);
	printf("char pointer to d: %p\n", dp);
	printf("char pointer to e: %p\n", ep);
	printf("char pointer to f: %p\n", fp);
	core.list.add(list, ap);
	printf("Is the list empty? %s\n", core.string.boolean_to_string(core.list.is_empty(list)));
	printf("LIST HAS 1 ELEMENT NOW!\n");
	show_list(list);
	core.list.insert(list, 0, bp);
	printf("LIST HAS 2 ELEMENTS NOW!\n");
	show_list(list);
	core.list.insert(list, 1, cp);
	printf("LIST HAS 3 ELEMENTS NOW!\n");
	show_list(list);
	core.list.insert(list, 3, dp);
	printf("LIST HAS 4 ELEMENTS NOW!\n");
	show_list(list);
	printf("Is the list empty? %s\n", core.string.boolean_to_string(core.list.is_empty(list)));
	show_list(list);
	core.list.set(list, 1, ep);
	core.list.set(list, 0, dp);
	core.list.set(list, 3, fp);
	printf("=== START OF CURSOR ANALYZE ===\n");
	printf("Getting index 2 ...\n");
	char* i2 = core.list.get(list, 2);
	show_cursor(list);
	printf("Getting index 1 ...\n");
	char* i1 = core.list.get(list, 1);
	show_cursor(list);
	printf("Getting index 3 ...\n");
	char* i3 = core.list.get(list, 3);
	show_cursor(list);
	printf("Getting index 0 ...\n");
	char* i0 = core.list.get(list, 0);
	show_cursor(list);
	printf("=== END OF CURSOR ANALYZE ===\n");
	printf("Element 2: %c (p=%p)\n", *i2, i2);
	printf("Element 1: %c (p=%p)\n", *i1, i1);
	printf("Element 3: %c (p=%p)\n", *i3, i3);
	printf("Element 0: %c (p=%p)\n", *i0, i0);
	printf("\n");
	printf("Printed with print\n");
	printf("\n");
	core.list.print(list, "%c");
	printf("\n");
	printf("Printed with println\n");
	printf("\n");
	core.list.println(list, "%c");
	printf("\n");
	printf("REMOVING ELEMENT 1 AND ELEMENT 3\n");
	core.list.remove(list, 3);
	printf("Removed 3\n");
	//printf("List length: %d\n", list->length);
	show_list(list);
	show_cursor(list);
	core.list.remove(list, 1);
	printf("Removed 1\n");
	//printf("List length: %d\n", list->length);
	show_list(list);
	show_cursor(list);
	core.list.remove(list, 0);
	printf("Removed 0\n");
	//printf("List length: %d\n", list->length);
	show_list(list);
	show_cursor(list);
	core.list.remove(list, 0);
	printf("Removed 0\n");
	//printf("List length: %d\n", list->length);
	show_list(list);
	show_cursor(list);
	core.list.destroy(list);
	return 1;
}

void show_cursor(List* list) {
	printf("Cursor position:\n");
	printf("Last accessed index:   %d\n", list->last_accessed_index);
	if (list != NULL && list->last_accessed != NULL) {
		printf("Last accessed pointer: %p\n", list->last_accessed);
	} else {
		printf("Last accessed pointer: (does not exist)\n");
	}
}

void show_list(List* list) {
	printf("List length: %d\n", list->length);
	printf("List start:  %p\n", list->start);
	printf("List end:    %p\n", list->end);
	printf("\n");
	int index = 0;
	while (index < list->length) {
		ListItem* item = core.list.get_item(list, index);
		printf("index:      %d\n", index);
		printf("previous:   %p\n", item->previous);
		printf("this:       %p\n", item);
		printf("pointer:    %p\n", item->pointer);
		printf("p. as char: %c\n", *(char*)(item->pointer));
		printf("next:       %p\n", item->next);
		printf("\n");
		index++;
	}
}

int test_char_list() {
	CharList* list = core.charlist.create();
	core.charlist.add(list, 'H');
	core.charlist.add(list, 'e');
	core.charlist.add(list, 'l');
	core.charlist.add(list, 'l');
	core.charlist.add(list, 'o');
	int length = core.charlist.get_length(list);
	if (length != 5) {
		printf("core.charlist.get_length() or core.charlist.add() does not work!\n");
		return 0;
	}
	char* string = core.charlist.to_string(list);
	if (!core.string.are_strings_equal(string, "Hello")) {
		printf("\"Hello\" is returned as \"%s\"!\n", string);
		printf("core.charlist.to_string() does not work!\n");
		return 0;
	}
	printf("core.charlist was tested successfully.\n");
	return 1;
}

int test_string_list() {
	StringList* list = core.stringlist.create();
	core.stringlist.add(list, "\"Hello ");
	core.stringlist.add(list, "World\" ");
	core.stringlist.add(list, "says ");
	core.stringlist.add(list, "the ");
	core.stringlist.add(list, "unit ");
	core.stringlist.add(list, "test!");
	int length = core.stringlist.get_length(list);
	if (length != 6) {
		printf("core.stringlist does not work!\n");
		return 0;
	}
	char** array = core.stringlist.to_array(list);
	printf("The string list contains following content:\n");
	int index = 0;
	while (index < length) {
		char* string = array[index];
		printf("%s", string);
		index++;
	}
	printf("End of string list.\n");
	printf("core.stringlist was tested successfully.\n");
	return 1;
}

int test_string() {
	char* string1 = "Hello";
	if (core.string.get_length(string1) != 5) {
		printf("core.string.get_length() does not work!\n");
		return 0;
	}
	char* string2 = " World!";
	char* string3 = " World!";
	char* string4 = " World?";
	int equal23 = core.string.are_strings_equal(string2, string3);
	int equal34 = core.string.are_strings_equal(string3, string4);
	if (!equal23 || equal34) {
		printf("core.string.are_strings_equal() does not work!\n");
		return 0;
	}
	char* message = core.string.concatenate_strings(string1, string2);
	if (!core.string.are_strings_equal(message, "Hello World!")) {
		printf("core.string.concatenate_strings() does not work!\n");
		return 0;
	}
	if (!core.string.is_substring(message, "o W", 4)) {
		printf("core.string.is_substring() does not work!\n");
		return 0;
	}
	char* part = core.string.get_substring(message, 4, 7);
	if (!core.string.are_strings_equal(part, "o W")) {
		printf("core.string.get_substring() does not work!\n");
		return 0;
	}
	if (!core.string.starts_with_string(message, "Hello Wo")) {
		printf("core.string.starts_with_string() does not work!\n");
		return 0;
	}
	if (!core.string.ends_with_string(message, "o World!")) {
		printf("core.string.ends_with_string() does not work!\n");
		return 0;
	}
	if (core.string.search_character(message, ' ') != 5) {
		printf("core.string.search_character does not work!\n");
		return 0;
	}
	printf("core.string was tested successfully.\n");
	return 1;
}
