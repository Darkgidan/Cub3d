#include "cub3d.h"
#include <sys/stat.h>
#include <fcntl.h>

void	printinput(t_scene *scene)
{
	int i = -1;
	printf("Resolution\nWidth %d\tHeight %d\n",scene->win.width,scene->win.height);
	printf("North texture %s\n",scene->nw.addr);
	printf("East texture %s\n",scene->ew.addr);
	printf("South texture %s\n",scene->sw.addr);
	printf("West texture %s\n",scene->ww.addr);
	printf("Sprite texture %s\n",scene->item_sprite.addr);
	printf("Floor Color %d,%d,%d\n",get_r(scene->bot_c)/(256 * 256),get_g(scene->bot_c)/256,get_b(scene->bot_c));
	printf("Ceiling Color %d,%d,%d\n",(get_r(scene->top_c)/(256 * 256)),(get_g(scene->top_c)/256),get_b(scene->top_c));
	printf("Map\nWidth %d\tHeight %d\n",scene->map.width,scene->map.height);
	while (scene->map.mat[++i])
		printf("%s\n",scene->map.mat[i]);
	printf("Player x %d, Player y %d\n",scene->pc.x, scene->pc.y);
}

char **ft_matdup(char **mat, int dim)
{
	char **res;
	int i = -1;

	res = ft_calloc(sizeof(char *), dim);
	while (++i < dim - 100)
	{
		res[i] = ft_strdup(mat[i]);
		free(mat[i]);
	}
	free(mat);
	return (res);
}

void	get_map(char **str, t_scene *scene)
{
	int i;
	int j;
	int len;
	char *spc;

	i = -1;
	while (str[++i])
	{
		len = ft_strlen(str[i]);
		if (len > scene->map.width)
			scene->map.width = len;
	}
	scene->map.height = i;
	i = -1;
	scene->map.mat = ft_calloc(sizeof(char *), (scene->map.height + 1));
	while (++i < scene->map.height)
	{
		j = 0;
		scene->map.mat[i] = ft_calloc(sizeof(char), (scene->map.width + 1));
		scene->map.mat[i] = ft_strdup(str[i]);
		len = scene->map.width - (int)ft_strlen(str[i]);
		if (len > 0)
		{
			spc = ft_calloc(sizeof(char), (len + 1));
			while(j < len)
				spc[j++] = ' ';
			scene->map.mat[i] = ft_strjoin3(scene->map.mat[i], spc);
		}
	}
	scene->map.mat[scene->map.height] = NULL;
	map_manager(scene);
}

int input_management(t_scene *scene)
{
	int fd;
	int i;
	int j;
	char **str;
	i = -1;
	j = -1;
	fd = open("input.cub", 00);
	str = ft_calloc(sizeof(char *), 101);
	while (get_next_line(fd, &str[++i]))
		if (i % 100 == 0 && i != 0)
			str = ft_matdup(str, i + 100);
	str[i + 1] = NULL;
	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][0] == '\0')
			;
		else if (str[i][0] == 'R')
			get_resolution(str[i], scene);
		else if(str[i][0] == 'N')
			get_north_texture(str[i], scene);
		else if(str[i][0] == 'S' && str[i][1] == 'O')
			get_east_texture(str[i], scene);
		else if(str[i][0] == 'W')
			get_south_texture(str[i], scene);
		else if(str[i][0] == 'E')
			get_west_texture(str[i], scene);
		else if(str[i][0] == 'S' && str[i][1] == ' ')
			get_sprite_texture(str[i], scene);
		else if(str[i][0] == 'F')
			get_floor_color(str[i], scene);
		else if(str[i][0] == 'C')
			get_ceiling_color(str[i], scene);
		else
		{
			get_map(&str[i], scene);
			break ;
		}
	}
	//printinput(scene);
	return (1);
}