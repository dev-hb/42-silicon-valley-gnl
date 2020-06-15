#include "../get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>

int main(int argc, char **argv)
{
	int fd;
	int ret;
	int line_count;
	char *line;

	line_count = 1;
	ret = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);

		// Reads from a file
		while ((ret = get_next_line(fd, &line)) > 0)
		{
			printf("[ MAIN while RET: %d] | A line has been read #%d => %s\n", ret, line_count, line);
			line_count++;
			free(line);
		}

		printf("\n");
		printf("[MAIN Return: %d] A line has been read #%d: %s\n", ret, line_count++, line);
		printf("\n");
		if (ret == -1)
			printf("-----------\n MAIN An error happened\n");
		else if (ret == 0)
			printf("-----------\n MAIN EOF has been reached\n");
		close(fd);
	}
	if (argc == 1)
	{
		while ((ret = get_next_line(0, &line)) > 0)
		{
			printf("[Return: %d] Line #%d: %s\n", ret, line_count, line);
			line_count++;
		}
		if (ret == -1)
			printf("\nAn error happened\n");
		else if (ret == 0)
			printf("\nEOF has been reached\n");
		close(fd);
	}
	return (0);
}