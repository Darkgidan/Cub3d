#include "cub3d.h"

void	get_north_texture(char *str, t_scene *scene)
{
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	scene->nw.addr = get_str(&str[i]);
}

void	get_east_texture(char *str, t_scene *scene)
{
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	scene->ew.addr = get_str(&str[i]);
}

void	get_south_texture(char *str, t_scene *scene)
{
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	scene->sw.addr = get_str(&str[i]);
}

void	get_west_texture(char *str, t_scene *scene)
{
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	scene->ww.addr = get_str(&str[i]);
}

void	get_sprite_texture(char *str, t_scene *scene)
{
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	scene->item_sprite.addr = get_str(&str[i]);
}