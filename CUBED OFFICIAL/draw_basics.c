#include "cub3d.h"

void drawImgsquare(int x, int y, int dim, int trgb, t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < dim)
			my_mlx_pixel_put(data, x + i, y + j, trgb);
	}
}

void drawImgVertLine(int x, int y, int dim, int trgb, t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < dim)
	{
		i = -1;
		while (++i < 1)
			my_mlx_pixel_put(data, x + i, y + j, trgb);
	}
}

void drawImgHoriLine(int x, int y, int dim, int trgb, t_data *data)
{
	int i;
	int j;

	j = -1;
	while (++j < 1)
	{
		i = -1;
		while (++i < dim)
			my_mlx_pixel_put(data, x + i, y + j, trgb);
	}
}

void draw_ray(t_scene *scene, int w, int h)
{
    int i;
    int j;
    int px,py;
    int dim = 5;

    i = (-1 * h) -1;
    while (++i < h)
    {
        j = (-1 * w) -1;
        while (++j < w)
        {
            px = ((dim) * (5)) - (dim / 2);
            py = ((dim) * (4)) - (dim / 2);
        }
    }
}