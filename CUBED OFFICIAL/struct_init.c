#include "cub3d.h"

void data_init(t_data *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = -1;
	data->line_length = -1;
	data->endian = -1;
	data->width = -1;
	data->height = -1;
}

void win_init(t_win *win)
{
	win->mlx = NULL;
	win->win = NULL;
	win->width = -1;
	win->height = -1;
	win->unit = -1;
	win->distproject = -1;
	win->scale = -1;
}
void pc_init(t_pc *pc)
{
	pc->x = -1;
	pc->y = -1;
	pc->alpha = -1;
	pc->fow = -1;
	pc->s_centre = -1;
	pc->rapporto = -1;
}

void map_init(t_map *map)
{
	map->mat = NULL;
	map->height = -1;
	map->width = -1;
}

void hook_init(t_hooks *hook)
{
	int i;

	i = -1;
	while(++i < 256)
		hook->active_keys[i] = 0;
	i = -1;
	while(++i < 256)
		hook->toggles_keys[i] = 0;
	hook->actkey = -1;
	hook->prekey = -1;
}

void scene_init(t_scene *scene)
{
	data_init(&scene->nw);
	data_init(&scene->ew);
	data_init(&scene->sw);
	data_init(&scene->ww);
	data_init(&scene->item_sprite);
	data_init(&scene->scene);
	win_init(&scene->win);
	pc_init(&scene->pc);
	map_init(&scene->map);
	hook_init(&scene->hook);
	scene->top_c = -1;
	scene->bot_c = -1;
}
