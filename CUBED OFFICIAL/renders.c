#include "cub3d.h"

void render_ceiling(t_scene *scene)
{
	int i;
	int j;

	i = -1;
	while (++i < scene->pc.s_centre)
	{
		j = -1;
		while(++j < scene->win.width)
			my_mlx_pixel_put(&scene->scene, j, i, scene->top_c);
	}
}

void render_floor(t_scene *scene)
{
	int i;
	int j;

	i = scene->pc.s_centre;
	i--;
	while (++i < scene->win.height)
	{
		j = -1;
		while(++j < scene->win.width)
			my_mlx_pixel_put(&scene->scene, j, i, scene->bot_c);
	}
}

void render_mini_map(t_scene *scene)
{
	int i;
	int j;
	int px;
	int py;
	int dim;
	int mx;//
	int my;//

	px = (int)scene->pc.x / (int)scene->win.unit;
	py = (int)scene->pc.y / (int)scene->win.unit;
	mx = px % 24;//
	my = py % 24;//
	i = -4;
	j = -5;
	//printf("px + j %d\n py + i %d\n",px + j,py + i);
	dim = scene->win.width / 48;
	while (++i < 4)
	{
		j = -5;
		//printf("px + j %d\n py + i %d\n",px+j,py+i);
		while (j++ < 5)
		{		
			if (px + j < 0 || px + j >= scene->map.width || py + i < 0 || py + i >= scene->map.height)
				drawImgsquare(((dim) * (j + 5)), ((dim) * (i + 4)), dim, Red, &scene->scene);
			else if (scene->map.mat[py + i][px + j] == '1')
				drawImgsquare(((dim) * (j + 5)), ((dim) * (i + 4)), dim, Red, &scene->scene);
			else
				drawImgsquare(((dim) * (j + 5)), ((dim) * (i + 4)), dim, GhostWhite, &scene->scene);
		}
	}
	drawImgsquare(((dim) * (5)), ((dim) * (4)), dim, Black, &scene->scene);
	drawImgVertLine(dim, dim, (dim * ((i * 2) - 1)), Black, &scene->scene);
	drawImgVertLine(dim * 11, dim, (dim * ((i * 2) - 1)), Black, &scene->scene);
	drawImgHoriLine(dim, dim, (dim * ((j * 2) - 2)), Black, &scene->scene);
	drawImgHoriLine(dim, dim * 8, (dim * ((j * 2) - 2)), Black, &scene->scene);
}


int render_next_frame(t_scene *scene)
{
	scene->scene.img = mlx_new_image(scene->win.mlx, scene->win.width, scene->win.height);
	scene->scene.addr = mlx_get_data_addr(scene->scene.img, &scene->scene.bits_per_pixel, &scene->scene.line_length, &scene->scene.endian);
	mlx_hook(scene->win.win, 2, 1L<<0, key_hook, scene);//keypress
	mlx_hook(scene->win.win, 3, 1L<<1, free_key, scene);//keyrelease
	keymanagement(scene);
	render_ceiling(scene);
	render_floor(scene);
	raycast(scene);
	if(scene->hook.toggles_keys[46])
		render_mini_map(scene);
	mlx_put_image_to_window(scene->win.mlx, scene->win.win, scene->scene.img, 0, 0);
	mlx_destroy_image(scene->win.mlx, scene->scene.img);
	return (1);
}
