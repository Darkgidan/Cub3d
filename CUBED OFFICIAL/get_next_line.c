#include "cub3d.h"

int get_next_line(int fd, char **line)
{
	int dim;
	char *str;
	static char *buff;

	dim = 1;
	if (!line || fd < 0)
		return (-1);
	str = gnl_calloc(sizeof(char), 2);
	if (!buff)
		buff = gnl_calloc(sizeof(char), 1);
	while (dim != 0 && find_n(buff) == 0)
	{
		if ((dim = read(fd, str, 1)) == -1)
		{
			free(str);
			free(buff);
			return (-1);
		}
		str[dim] = 0;
		buff = gnl_strjoin(buff, str);
	}
	free(str);
	*line = gnl_strndup(buff);
	free(buff);
	buff = NULL;
	return (dim);
}