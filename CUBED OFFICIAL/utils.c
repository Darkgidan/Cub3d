#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		get_pixel_data(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

double rad(double alpha)
{
	return (alpha * PI / 180);
}


double grades(double alpha)
{
	return (alpha / PI * 180);
}

int ft_abs(int a)
{
	if(a < 0)
		return (-a);
	return (a);
}

void wall_seen(t_scene *scene, int *wall, int dx, int dy)
{
	*wall = 0;
	if (dx % scene->win.unit == 0)
		*wall = *wall + 8;//o
	if (dx % scene->win.unit == scene->win.unit - 1)
		*wall = *wall+ 2;//e
	if (dy % scene->win.unit == 0)
		*wall = *wall + 1;//n
	if (dy % scene->win.unit == scene->win.unit - 1)
		*wall = *wall + 4;//s
}

double pitagora(t_scene *scene, double x, double y)
{
	double x1;
	double y1;

	x1 = scene->pc.x;
	y1 = scene->pc.y;
	return (sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)));
}

void	 angle_fix_rad(double *angle)
{
	if (*angle >= (PI + PI))
		*angle = *angle - (PI + PI);
	else if (*angle < 0.0f)
		*angle = (PI + PI) + *angle;

}

void	 angle_fix(double *angle)
{
	if (*angle >= 360.0f)
		*angle = *angle - 360.0f;
	else if (*angle < 0.0f)
		*angle = 360.0f + *angle;
}


/*
        1111111111111111111111111
        10000000000110000000000001
        1011000001110000002000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10002000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
*/