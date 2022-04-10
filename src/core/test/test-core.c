#include <stdio.h>

#ifdef CORETEST

int main(int argc, char** argv) {
	printf("Executed core test successfully (%d parameters, %p is the pointer).\n", argc, argv);
	return 1;
}

#endif
