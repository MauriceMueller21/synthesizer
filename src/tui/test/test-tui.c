#include <stdio.h>
#ifdef TUITEST
int main(int argc, char** argv) {
	printf("Executed tui test successfully (%d parameters, %p is the pointer).\n", argc, argv);
	return 1;
}
#endif
