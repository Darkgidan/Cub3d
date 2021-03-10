#include "cub3d.h"

t_scene scene;

int main()
{
	scene_init(&scene);
	scene.win.mlx = mlx_init();
	input_management(&scene);
	scene.win.win = mlx_new_window(scene.win.mlx, scene.win.width, scene.win.height, "Main Window");
	scene.win.unit = 256;
	scene.pc.fow = 60.0;
	scene.pc.x = (scene.pc.x * scene.win.unit) + (scene.win.unit / 2);
	scene.pc.y = (scene.pc.y * scene.win.unit) + (scene.win.unit / 2);
	scene.win.distproject = (scene.win.width / 2) / tan(rad(scene.pc.fow / 2));
	scene.pc.rapporto = scene.win.unit * scene.win.distproject;
	scene.pc.s_centre = scene.win.height / 2;
	scene.win.scale = scene.item_sprite.width / scene.win.unit;
	get_texture(&scene);
	print_scene(scene);
	mlx_loop_hook(scene.win.mlx, render_next_frame, &scene);
	mlx_loop(scene.win.mlx);
}