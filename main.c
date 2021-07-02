#include "get_next_line.h"
#include <stdio.h>

void f(void)
{
	system("leaks a.out");
}

int main()
{
	int fd;
	int ret;
	char *test;
	
    test= NULL;
	ret = 0;
	fd = open("test.txt", O_RDONLY);
	// fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	if (!(fd = open("test.txt", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((ret = get_next_line(fd, &test)) > 0)
	{
		printf("|%s|\n", test);
		free(test);
	}
	printf("|%s|\n", test);
	free(test);
	atexit(f);
	close(fd);
	return (0);
}