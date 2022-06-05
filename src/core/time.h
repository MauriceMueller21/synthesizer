#pragma once

typedef struct TimeFunctions {
	void (*sleep)(int milliseconds);
} TimeFunctions;

extern TimeFunctions time_functions;

void core_time_initialize();
