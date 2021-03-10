#include "cub3d.h"

int trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_t(int trgb)
{
	return (trgb & (0xFF000000));
}

int get_r(int trgb)
{
	return (trgb & (0x00FF0000));
}

int get_g(int trgb)
{
	return (trgb & (0x0000FF00));
}

int get_b(int trgb)
{
	return (trgb & (0x000000FF));
}
/*int get_opposite(int trgb)
{
	return (~trgb);
}

int add_shade(int trgb, double distance)
{
	return (((int)(255 * distance) << 24) | (get_r(trgb)) | get_g(trgb) | get_b(trgb));
}*/
