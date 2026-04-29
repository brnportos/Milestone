#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("README.md", O_RDONLY);
    if (fd == -1)
        return (1);
    char    *gnl = get_next_line(fd);

    while (gnl)
    {
        printf("%s", gnl);
        free(gnl);
        gnl = NULL;
        gnl = get_next_line(fd);
    }
    close(fd);
}
