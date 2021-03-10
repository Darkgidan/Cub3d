#include "cub3d.h"

int		get_number(char *str)
{
	int res;
	int i;

	res = 0;
	i = -1;
	while(str[++i] <= '9' && str[i] >= '0')
		res = res * 10 + str[i] - '0';
	return (res);
}

char	*get_str(char *src)
{
	char *str;
	int i;

	i = 0;
	str = ft_calloc(sizeof(char), ft_strlen(src) + 1);
	while (*src)
	{
		while (*src == ' ')
			src++;
		str[i] = *src;
		i++;
		src++;
	}
	return (str);
}

void	get_resolution(char *str, t_scene *scene)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	scene->win.width = get_number(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ')
		i++;
	scene->win.height = get_number(&str[i]);
}



void	get_floor_color(char *str, t_scene *scene)
{
	int r;
	int g;
	int b;
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	r = get_number(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	g = get_number(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	b = get_number(&str[i]);
	scene->bot_c = trgb(0, r, g, b);
}

void	get_ceiling_color(char *str,t_scene *scene)
{
	int r;
	int g;
	int b;
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	r = get_number(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	g = get_number(&str[i]);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i++;
	b = get_number(&str[i]);
	scene->top_c = trgb(0, r, g, b);
}