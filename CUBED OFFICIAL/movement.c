#include "cub3d.h"

void	move_W_S(t_scene *s, double move, int u)
{
	int dim = 100;
	if (s->hook.active_keys[1])//S
	{
		if (s->map.mat[(int)((s->pc.y + (move * sin(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x - (move * cos(rad(s->pc.alpha)))) / u)] != '1')
		{
			s->pc.x -= (int)(move * cos(rad(s->pc.alpha)));
			s->pc.y += (int)(move * sin(rad(s->pc.alpha)));
		}
		else if(s->map.mat[(int)((s->pc.y + (move * sin(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x) / u)] != '1')
			s->pc.y += (int)(move * sin(rad(s->pc.alpha)));
		else if (s->map.mat[(int)((s->pc.y) / u)]
		[(int)((s->pc.x - (move * cos(rad(s->pc.alpha)))) / u)] != '1')
			s->pc.x -= (int)(move * cos(rad(s->pc.alpha)));
	}
	if (s->hook.active_keys[13])//W
	{
		if (s->map.mat[(int)((s->pc.y - (move * sin(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x + (move * cos(rad(s->pc.alpha)))) / u)] != '1')
		{
			s->pc.x += (int)(move * cos(rad(s->pc.alpha)));
			s->pc.y -= (int)(move * sin(rad(s->pc.alpha)));
		}
		else if(s->map.mat[(int)((s->pc.y - (move * sin(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x) / u)] != '1')
			s->pc.y -= (int)(move * sin(rad(s->pc.alpha)));
		else if (s->map.mat[(int)((s->pc.y) / u)]
		[(int)((s->pc.x + (move * cos(rad(s->pc.alpha)))) / u)] != '1')
			s->pc.x += (int)(move * cos(rad(s->pc.alpha)));
	}
}

void	move_A_D(t_scene *s, double move, int u)
{
	int dim =  s->win.unit / 2;
	if (s->hook.active_keys[0])//A
	{
		if (s->map.mat[(int)((s->pc.y - (move * cos(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x - (move * sin(rad(s->pc.alpha)))) / u)] != '1')
		{
			s->pc.x -= (int)(move * sin(rad(s->pc.alpha)));
			s->pc.y -= (int)(move * cos(rad(s->pc.alpha)));
		}
		else if (s->map.mat[(int)((s->pc.y) / u)]
		[(int)((s->pc.x- (move * sin(rad(s->pc.alpha)))) / u)] != '1')
			s->pc.x -= (int)(move * sin(rad(s->pc.alpha)));
		else if (s->map.mat[(int)((s->pc.y - (move * cos(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x) / u)] != '1')
			s->pc.y -= (int)(move * cos(rad(s->pc.alpha)));
	}
	if (s->hook.active_keys[2])//D
	{
		if (s->map.mat[(int)((s->pc.y + (move * cos(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x + (move * sin(rad(s->pc.alpha)))) / u)] != '1')
		{
			s->pc.x += (int)(move * sin(rad(s->pc.alpha)));
			s->pc.y += (int)(move * cos(rad(s->pc.alpha)));
		}
		else if (s->map.mat[(int)((s->pc.y) / u)]
		[(int)((s->pc.x + (move * sin(rad(s->pc.alpha)))) / u)] != '1')
			s->pc.x += (int)(move * sin(rad(s->pc.alpha)));
		else if (s->map.mat[(int)((s->pc.y + (move * cos(rad(s->pc.alpha)))) / u)]
		[(int)((s->pc.x) / u)] != '1')
			s->pc.y += (int)(move * cos(rad(s->pc.alpha)));
	}
}


void	move_player(t_scene *s)
{
	double move;
	int u;//unit

	move = s->win.unit / 10;
	u = s->win.unit;
	move_W_S(s, move, u);
	move_A_D(s, move, u);
}