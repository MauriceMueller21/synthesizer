#include "gui/widget.h"
#include "core/core.h"
#include "core/extensions.h"
#include <stdlib.h>

void push_only_named_widget(WidgetList* list, SWidget* widget)
{
	if (widget->identifier) {
		core_list_push(list, widget);
	} else {
		free(widget);
	}
}

