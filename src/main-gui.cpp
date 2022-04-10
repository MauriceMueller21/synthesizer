#include "gui/test.h"
#include <stdio.h>
#include <unistd.h>

int main(int argc, char** argv)
{
	int option;
	while ((option = getopt(argc, argv, "ht")) != -1)
	{
		if (option == 'h')
		{
			printf("Usage: %s [-ht] \n", argv[0]);
			return 0;
		}
		
		if (option == 't')
		{
			return test_graphics_manually();
		}
	}
	return 0;
}

