#include "cub3d.h"

void get_texture(t_scene *scene)
{
	scene->nw.img = mlx_xpm_file_to_image(scene->win.mlx, scene->nw.addr,
	&scene->nw.width, &scene->nw.height);
	scene->nw.addr = mlx_get_data_addr(scene->nw.img, &scene->nw.bits_per_pixel,
	&scene->nw.line_length, &scene->nw.endian);
	scene->ew.img = mlx_xpm_file_to_image(scene->win.mlx, scene->ew.addr,
	&scene->ew.width, &scene->ew.height);
	scene->ew.addr = mlx_get_data_addr(scene->ew.img, &scene->ew.bits_per_pixel,
	&scene->ew.line_length, &scene->ew.endian);
	scene->sw.img = mlx_xpm_file_to_image(scene->win.mlx, scene->sw.addr,
	&scene->sw.width, &scene->sw.height);
	scene->sw.addr = mlx_get_data_addr(scene->sw.img, &scene->sw.bits_per_pixel,
	&scene->sw.line_length, &scene->sw.endian);
	scene->ww.img = mlx_xpm_file_to_image(scene->win.mlx, scene->ww.addr,
	&scene->ww.width, &scene->ww.height);
	scene->ww.addr = mlx_get_data_addr(scene->ww.img, &scene->ww.bits_per_pixel,
	&scene->ww.line_length, &scene->ww.endian);
	scene->item_sprite.img = mlx_xpm_file_to_image(scene->win.mlx,
	scene->item_sprite.addr, &scene->item_sprite.width,
	&scene->item_sprite.height);
	scene->item_sprite.addr = mlx_get_data_addr(scene->item_sprite.img,
	&scene->item_sprite.bits_per_pixel, &scene->item_sprite.line_length,
	&scene->item_sprite.endian);
}