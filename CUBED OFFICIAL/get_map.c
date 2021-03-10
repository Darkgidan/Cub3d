#include "cub3d.h"


int is_map_valid(t_scene *scene)
{
	int i;
	int j;

	i = -1;
	while (++i < scene->map.height)
	{
		j = -1;
		while(++j < scene->map.width)
		{
			if ((i == 0 || j == 0 || i == (scene->map.height - 1)
			|| j == scene->map.width - 1) && !(scene->map.mat[i][j] == '1' || scene->map.mat[i][j] == ' '))
				return (-1);
			if (scene->map.mat[i][j] != '1' && scene->map.mat[i][j] != ' ')
				if ((scene->map.mat[i+1][j] == ' ') ||
				(scene->map.mat[i][j+1] == ' ') ||
				(scene->map.mat[i-1][j] == ' ') ||
				(scene->map.mat[i][j-1] == ' '))
				return(-1);
		}
	}
	i = -1;
	while (++i < scene->map.height)
	{
		j = -1;
		while(++j < scene->map.width)
			if (scene->map.mat[i][j] == ' ')
				scene->map.mat[i][j] = '1';
	}
	return (1);
}

int		map_manager(t_scene *scene)
{
	int i;
	int j;

	i = -1;
	if ((is_map_valid(scene)) == -1)
		return (-1);
	else
	{
		while (scene->map.mat[++i])
		{
			j = -1;
			while (scene->map.mat[i][++j])
				if (scene->map.mat[i][j] == 'N' || scene->map.mat[i][j] == 'E' ||
				scene->map.mat[i][j] == 'S' || scene->map.mat[i][j] == 'W')
				{
					scene->pc.x = j;
					scene->pc.y = i;
					if (scene->map.mat[i][j] == 'N')
						scene->pc.alpha = 90;
					else if (scene->map.mat[i][j] == 'E')
						scene->pc.alpha = 0;
					else if (scene->map.mat[i][j] == 'S')
						scene->pc.alpha = 270;
					else
						scene->pc.alpha = 180;
				}
		}
		return (1);
	}
}
