#include "cub3d.h"

int gnl_strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char *gnl_calloc(int size, int dim)
{
	char *res;
	int i = 0;

	res = malloc(size * dim);
	while (i < dim)
		res[i++] = 0;
	return (res);
}

char *gnl_strjoin(char *s1,char *s2)
{
	int i = -1;
	int j = -1;
	char *res;

	res = gnl_calloc(sizeof(char), gnl_strlen(s1) + gnl_strlen(s2) + 1);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = 0;
	free(s1);
	return(res);
}

char *gnl_strndup(char *str)
{
	int i = -1;
	char *res;

	res = gnl_calloc(sizeof(char), gnl_strlen(str) + 1);
	while(str[++i] && str[i] != '\n')
		res[i] = str[i];
	return(res);
}

int find_n(char *str)
{
	int i = 0;

	while (str[i])
		if(str[i] == '\n')
			return (1);
		else
			i++;
	return (0);
}