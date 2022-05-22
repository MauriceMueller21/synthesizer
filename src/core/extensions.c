#include "core/extensions.h"
#include "core/core.h"

void* core_list_peek(List* list)
{
	int length = core.list.get_length(list);
	return core.list.get(list, length - 1);
}

void core_list_push(List* list, void* item)
{
	core.list.add(list, item);
}

void core_list_pop(List* list)
{
	int length = core.list.get_length(list);
	core.list.remove(list, length - 1);
}

void core_list_iterate(List* list, void (*callback)(void*))
{
	for (int i = 0; i < core.list.get_length(list); i++)
	{
		callback(core.list.get(list, i));
	}
}

