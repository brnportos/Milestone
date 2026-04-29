#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	if (len > (ft_strlen(s) - start))
		len = (ft_strlen(s) - start);
	sub = malloc(sizeof * sub * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}

static char    *read_join(int fd, char *tmp)
{
    char    *buf;
    char    *keep_tmp;
    ssize_t     size;

    size = 1;
    if (!tmp)
        tmp = ft_strdup("");
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    while (!ft_strchr(tmp, '\n') && size > 0)
    {
        size = read(fd, buf, BUFFER_SIZE);
        if (size == -1)
            return (free(tmp), free(buf), NULL);
        buf[size] = '\0';
        keep_tmp = tmp;
        tmp = ft_strjoin(keep_tmp, buf);
        free(keep_tmp);
    }
    return (free(buf), tmp);
}

static char	*line_extraction(char *tmp)
{
	int		i;
	char	*line;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	line = ft_substr(tmp, 0, i + (tmp[i] == '\n'));
	return (line);
}

static char	*moving_next_line(char *tmp)
{
    char    *keep_tmp;
    int i;

    i = 0;
    while (tmp[i] && tmp[i] != '\n')
        i++;
    if (!tmp[i])
        return (free(tmp), tmp = NULL, NULL);
    keep_tmp = ft_substr(tmp, i + 1, ft_strlen(tmp) - i);
    free(tmp);
    return (keep_tmp);
}

char *get_next_line(int fd)
{
    char    *line;
    static char *tmp[1024];

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp[fd] = read_join(fd, tmp[fd]);
    if (!tmp[fd])
        return (NULL);
    line = line_extraction(tmp[fd]);
    tmp[fd] = moving_next_line(tmp[fd]);
    return (line);
}
