#include <stdio.h>
#ifdef SOUNDTEST
int main(int argc, char** argv) {
	printf("Executed sound test successfully (%d parameters, %p is the pointer).\n", argc, argv);
}
#endif
