#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		i;

	i = 1;
	fd = open("toto", O_RDONLY);
	while ((line = get_next_line(fd)) && i <= 20)
    {
        printf("\nLigne %d --> %s\n", i, line);
        free(line);
        i++;
    }
	return (0);
}
