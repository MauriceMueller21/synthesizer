#include "../core.h"

#include <stdio.h>

void test_list();

void show_list(VoidPointerList* list);

void show_cursor(VoidPointerList* list);

#ifdef CORETEST

int main(int argc, char** argv) {
	core_initialize();
	test_list();
	printf("Executed core test successfully (%d parameters, %p is the pointer).\n", argc, argv);
	return 1;
}

#endif

void test_list() {
	VoidPointerList* list = core.list.create();
	printf("Address of list: %p\n", list);
	printf("Is the list empty? %s\n", core.string.bool_to_string(core.list.is_empty(list)));
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
	printf("Is the list empty? %s\n", core.string.bool_to_string(core.list.is_empty(list)));
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
	printf("Is the list empty? %s\n", core.string.bool_to_string(core.list.is_empty(list)));
	show_list(list);
	core.list.set(list, 1, ep);
	core.list.set(list, 0, dp);
	core.list.set(list, 3, fp);
	printf("=== START OF CURSOR ANALYZE ===\n");
	printf("Getting index 2 ...\n");
	Item* item = core.list.get(list, 2);
	char* i2 = item->pointer;
	show_cursor(list);
	printf("Getting index 1 ...\n");
	item = core.list.get(list, 1);
	char* i1 = item->pointer;
	show_cursor(list);
	printf("Getting index 3 ...\n");
	item = core.list.get(list, 3);
	char* i3 = item->pointer;
	show_cursor(list);
	printf("Getting index 0 ...\n");
	item = core.list.get(list, 0);
	char* i0 = item->pointer;
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
}

void show_cursor(VoidPointerList* list) {
	printf("Cursor position:\n");
	printf("Last accessed index:   %d\n", list->last_accessed_index);
	if (list != NULL && list->last_accessed != NULL) {
		printf("Last accessed pointer: %p\n", list->last_accessed);
	} else {
		printf("Last accessed pointer: (does not exist)\n");
	}
}

void show_list(VoidPointerList* list) {
	printf("List length: %d\n", list->length);
	printf("List start:  %p\n", list->start);
	printf("List end:    %p\n", list->end);
	printf("\n");
	int index = 0;
	while (index < list->length) {
		Item* item = core.list.get(list, index);
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
