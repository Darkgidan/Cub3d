#include "cub3d.h"

int key_hook(int keycode, t_scene *s)
{
	//printf("Keycode : %d is Pressed\n", keycode);
	if (keycode == 53)
	{
		mlx_clear_window(s->win.mlx, s->win.win);
		mlx_destroy_window(s->win.mlx, s->win.win);
		exit(0);
	}
	if (s->hook.active_keys[keycode] == 0)
		s->hook.toggles_keys[keycode] = !s->hook.toggles_keys[keycode];
	s->hook.active_keys[keycode] = 1;
	return (1);
}

int free_key(int keycode, t_scene *s)
{
	//printf("Keycode : %d is released\n", keycode);
	s->hook.active_keys[keycode] = 0;
	return (1);
}

int mouse_hook(int button, int x, int y, t_scene *s)
{
	//printf("Button : %d \t X : %d \t Y: %d\n", button, x, y);
	return (1);
}

void	rotate_player(t_scene *s)
{
	if (s->hook.active_keys[126] && (s->pc.s_centre + 10) < s->win.height)
		s->pc.s_centre += 10;
	if (s->hook.active_keys[125] && (s->pc.s_centre - 10) > 0)
		s->pc.s_centre -= 10;
	if (s->hook.active_keys[123])
		s->pc.alpha += (s->pc.fow / 20);
	if (s->hook.active_keys[124])
		s->pc.alpha -= (s->pc.fow / 20);
}

void keymanagement(t_scene *s)
{
	int i;

	i = -1;
	if (s->hook.active_keys[123] || s->hook.active_keys[124] || s->hook.active_keys[125] || s->hook.active_keys[126])
		rotate_player(s);
	if (s->hook.active_keys[13] || s->hook.active_keys[0] || s->hook.active_keys[1]|| s->hook.active_keys[2] )
		move_player(s);
}