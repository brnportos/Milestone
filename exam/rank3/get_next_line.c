#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define BUFFER_SIZE 10000

char	*get_next_line(int fd)
{
	char	*buff = malloc(BUFFER_SIZE);
	char	c;
	int		i = 0;
	int		val = 0;

	if (fd < 0 || !buff)
		return (free(buf), NULL);
	while ((val = read(fd, &c, 1)) > 0)
	{
		buff[i++] = c;
		if (c == '\n')
			break ;
	}
	if (val < 0 || i == 0)
	{
		free(buff);
		return (NULL);
	}
	buff[i] = '\0';
	return (buff);
}

#include <stdio.h>
int		main()
{
	int 	fd = 0;
	char	*line;

	fd = open("README.md", O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
