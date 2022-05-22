#pragma once
typedef struct List List;

/**
 * Returns a pointer to the last element of the list. Throws an exception if
 * the list does not contain an element.
 */
void* core_list_peek(List* list);

/**
 * Pushes a pointer to the new item at the end of the list.
 */
void core_list_push(List* list, void* item);

/**
 * Removes a pointer to the last element of the list. Throws an exception if
 * the list does not contain an element.
 */
void core_list_pop(List* list);

/**
 * Calls the given callback function for all items inside the list.
 */
void core_list_iterate(List* list, void (*callback)(void*));

