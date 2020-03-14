#include "get_next_line.h"

int main(int argc, char **argv)
{
	int fd;
	char *line = NULL;
	ssize_t gnl;

	argc++;
	fd = open(argv[1], O_RDONLY);
	while ((gnl = get_next_line(fd, &line)) ==  1)
	{
		printf("gnl: %zd--> *line: %s\n", gnl, line);
		free(line);
	}
	if (gnl == 0)
	{
		printf("gnl: %zd--> *line: %s\n", gnl, line);
		free(line);
	}
	system("leaks a.out");
	close(fd);
	return (0);
}
