#include "gui/widget.h"
#include "core/core.h"
#include <stdlib.h>

void push_only_named_widget(WidgetList* list, SWidget* widget)
{
	if (widget->identifier) {
		core.list.push(list, widget);
	} else {
		free(widget);
	}
}

