#include "get_next_line.h"

#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("text.txt", O_RDONLY);
	char	**line;

	while (get_next_line(fd, line))
	{
		printf("%s", *line);
		write(1, "\n-----------\n", 13);
	}
	printf("%s", *line);
	write(1, "\n-----------\n", 13);
}