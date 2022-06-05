#include "time.h"

#include <unistd.h>

TimeFunctions time_functions;

void core_time_sleep(int milliseconds) {
	usleep(1000 * milliseconds);
}

void core_time_initialize() {
	time_functions.sleep = &core_time_sleep;
}
