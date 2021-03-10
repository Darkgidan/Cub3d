#include "cub3d.h"

double get_horizontal(t_scene *scene, double alpha, int *wall)
{
	double ax;
	double ay;
	double dy;
	double dx;

	if (alpha >  PI)
		ay = (scene->pc.y / scene->win.unit) * (scene->win.unit) + scene->win.unit;
	else
		ay = (scene->pc.y / scene->win.unit) * (scene->win.unit) - 1;
	dx = scene->win.unit / tan(alpha);
	if ((alpha < (PI / 2)) || (alpha > (PI * 3 / 2)))
	{
		if (dx < 0)
			dx *= -1;
	}
	else if (dx > 0)
			dx *= -1;
	dy = scene->win.unit;
	if (alpha > PI)
	{
		if(dy < 0)
			dy *= -1;
	}
	else if (dy > 0)
		dy *= -1;
	ax = scene->pc.x + ((scene->pc.y - ay) / tan(alpha));
	if ((ay/scene->win.unit) < 0 || (ax/scene->win.unit) < 0 || (ay/scene->win.unit) >= scene->map.height || (ax/scene->win.unit) >= scene->map.width)
		return (-1.0);
	while (scene->map.mat[(int)ay/scene->win.unit][(int)ax/scene->win.unit] != '1')
	{
		ax += dx;
		ay += dy;
		if ((ay/scene->win.unit) < 0 || (ax/scene->win.unit) < 0 || (ay/scene->win.unit) >= scene->map.height || (ax/scene->win.unit) >= scene->map.width)
			return (-1.0);
	}
	wall_seen(scene, wall, ax, ay);
	scene->xhor = (int)ax % scene->win.unit;
	return (pitagora(scene, ax, ay));
}

double get_vertical(t_scene *scene, double alpha, int *wall)
{
	double ax;
	double ay;
	double dy;
	double dx;

	if ((alpha < (PI / 2)) || (alpha > (PI * 3 / 2)))
		ax = (scene->pc.x / scene->win.unit) * (scene->win.unit) + scene->win.unit;
	else
		ax = (scene->pc.x / scene->win.unit) * (scene->win.unit) - 1;
	dx = scene->win.unit;
	if ((alpha < (PI / 2)) || (alpha > (PI * 3 / 2)))
	{
		if (dx < 0)
			dx *= -1;
	}
	else if (dx > 0)
			dx *= -1;
	dy = scene->win.unit * tan(alpha);
	if (alpha < PI)
	{
		if(dy > 0)
			dy *= -1;
	}
	else if (dy < 0)
			dy *= -1;
	ay = scene->pc.y + ((scene->pc.x - ax) * tan(alpha));
	if ((ay/scene->win.unit) < 0 || (ax/scene->win.unit) < 0 || (ay/scene->win.unit) >= scene->map.height || (ax/scene->win.unit) >= scene->map.width)
		return (-1.0);
	while (scene->map.mat[(int)ay/scene->win.unit][(int)ax/scene->win.unit] != '1')
	{
		ax += dx;
		ay += dy;
		if ((ay/scene->win.unit) < 0 || (ax/scene->win.unit) < 0 || (ay/scene->win.unit) >= scene->map.height || (ax/scene->win.unit) >= scene->map.width)
			return (-1.0);
	}
	wall_seen(scene, wall, ax, ay);
	scene->xver = (int)ay % scene->win.unit;
	return (pitagora(scene, ax, ay));
}

void put_wall(t_scene *scene, int i, int j, int y)
{
	int x = scene->xwall * (scene->nw.width / scene->win.unit);

	if (scene->wall == 1)
		my_mlx_pixel_put(&scene->scene, i, j, get_pixel_data(&scene->nw, x, (int)y));
	else if (scene->wall == 8)
		my_mlx_pixel_put(&scene->scene, i, j, get_pixel_data(&scene->ww, x, (int)y));
	else if (scene->wall == 4)
		my_mlx_pixel_put(&scene->scene, i, j, get_pixel_data(&scene->sw, x, (int)y));
	else if (scene->wall == 2)
		my_mlx_pixel_put(&scene->scene, i, j, get_pixel_data(&scene->ew, x, (int)y));
	else
		my_mlx_pixel_put(&scene->scene, i, j, Gold);
		
}

void put_col(t_scene *scene, int pixs, int i)
{
	int j;
	int k;
	int x;
	double dy;
	double y;
	
	x = scene->xwall * (scene->nw.width / scene->win.unit);
	dy = (double)((double)scene->nw.height / (double) pixs);
	pixs = (pixs > scene->win.height) ? scene->win.height : pixs;
	y = scene->nw.height / 2 + dy;
	j = scene->pc.s_centre;
	pixs = j < 0 ? pixs + j: pixs;
	j = j < 0 ? 0 : j;
	k = -1;
	while (++k < (pixs / 2) && j-- > 0 && (y= y - dy))
		put_wall(scene, i, j, y);
	j = scene->pc.s_centre - 1;
	y = scene->nw.height / 2;
	k--;
	y-=dy;
	while (++k < (pixs) && j++ < scene->win.height && (y= y + dy))
		put_wall(scene, i, j, y);
}

double get_distance(t_scene *scene, double gamma)
{
	double res = -1.0;
	double res1 = -1.0;
	double dist;
	int wallh;
	int wallv;

	if (gamma != PI && gamma != 0.0)
		res = get_horizontal(scene, gamma, &wallh);
	if (gamma != (3 * PI / 2) && gamma != (PI / 2))
		res1 = get_vertical(scene, gamma, &wallv);
	scene->wall = wallv;
	scene->xwall = scene->xver;
	if ((res < res1 && res != -1.0) || res1 == -1.0)
	{
		dist = res;
		scene->wall = wallh;
		scene->xwall = scene->xhor;
	}
	else
		dist = res1;
	dist = dist * fabs(cos(gamma - rad(scene->pc.alpha)));
	dist = ft_abs(dist);
	return (dist);
}

void raycast(t_scene *scene)
{
	double gamma;
	int i;
	double dist;
	double pixs;

	i = 0;
	while (i < scene->win.width)
	{
		gamma = atan((i - (scene->win.width / 2)) / scene->win.distproject);
		angle_fix(&scene->pc.alpha);
		gamma = rad(scene->pc.alpha) - gamma;
		gamma = grades(gamma);
		angle_fix(&gamma);
		gamma = rad(gamma);
		dist = get_distance(scene, gamma);
		pixs = (scene->pc.rapporto / dist);
		//if ((int)pixs > scene->win.height)
		//	pixs = scene->win.height;
		put_col(scene, (int)pixs, i);
		i++;
	}
	return ;
}