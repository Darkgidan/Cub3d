#include "cub3d.h"

void	print_data(t_data data)
{
	printf("Data Path %s\n", data.addr);
	printf("Img Address %p\n", data.img);
	printf("Bits Per Pixel %d\n", data.bits_per_pixel);
	printf("Line Lenght %d\n", data.line_length);
	printf("Endian %d\n", data.endian);
	printf("Width %d\n", data.width);
	printf("Height %d\n", data.height);
}

void	print_win(t_win win)
{
	printf("Mlx Address %p\n", win.mlx);
	printf("Win Address %p\n", win.win);
	printf("Window Width %d\n", win.width);
	printf("Window Height %d\n", win.height);
	printf("Window Unit %d\n", win.unit);
}

void	print_pc(t_pc pc)
{
	printf("Player x %d\n", pc.x);
	printf("Player y %d\n", pc.y);
	printf("Player Alpha %.3f\n", pc.alpha);
	printf("Player FoW %.3f\n", pc.fow);
}

void	print_map(t_map map)
{
	int i;

	i = -1;
	printf("Map Width %d\n", map.width);
	printf("Map Height %d\n", map.height);
	printf("Map Layout :\n\n");
	while (map.mat[++i])
		printf("%s\n", map.mat[i]);
}

void	print_scene(t_scene scene)
{
	printf("North Wall Texture\n");
	print_data(scene.nw);
	printf("\nEast Wall Texture\n");
	print_data(scene.ew);
	printf("\nSouth Wall Texture\n");
	print_data(scene.sw);
	printf("\nWest Wall Texture\n");
	print_data(scene.ww);
	printf("\nItem Sprite Texture\n");
	print_data(scene.item_sprite);
	printf("\nGame Window\n");
	print_win(scene.win);
	printf("\nPlayer Info\n");
	print_pc(scene.pc);
	printf("\nLevel Map\n");
	print_map(scene.map);
	printf("\nCeiling Color :  %X\n", scene.top_c);
	printf("\nFloor Color :    %X\n", scene.bot_c);
}

