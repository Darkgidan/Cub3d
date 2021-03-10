#ifndef CUB3D_H
# define CUB3D_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <float.h>
#include <limits.h>
#include <stdbool.h>

#define PI 3.14159265359

enum colors {
	Red			= 0x00FF0000,
	Orange		= 0x00FF8C00,
	Yellow		= 0x00FFFF00,
	Gold		= 0x00FFD700,
	GhostWhite	= 0x00F8F8FF,
	Black		= 0x00000000,
	Purple		= 0x00800080,
	Pink		= 0x00FFC0CB,
	Lime		= 0x0000FF00,
	Cyan		= 0x0000FFFF,
	Acqua		= 0x0000FFFF,
	Blue		= 0x000000FF,
	Indigo		= 0x004b0082,
	Violet		= 0x00EE82EE
};

typedef struct	s_data {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct	s_win {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			unit;
	double		distproject;
	double		scale;
}				t_win;

typedef struct	s_pc {
	int			x;
	int			y;
	double		alpha;
	double		fow;
	double		rapporto;
	double		s_centre;
}				t_pc;

typedef struct	s_map {
	char		**mat;
	int			height;
	int			width;
}				t_map;

typedef struct	s_hooks {
	int			actkey;
	int			prekey;
	bool		active_keys[257];
	bool		toggles_keys[257];
}				t_hooks;

typedef struct	s_scene {
	t_data		nw;
	t_data		ew;
	t_data		sw;
	t_data		ww;
	t_data		item_sprite;
	t_data		scene;
	t_hooks		hook;
	t_win		win;
	t_pc		pc;
	t_map		map;
	int			top_c;//ceiling color
	int			bot_c;//floor color
	int			xhor;
	int			xver;
	int			xwall;
	int			wall;
}				t_scene;

/* get_next_line_utils */
int				gnl_strlen(char *str);
char			*gnl_calloc(int size, int dim);
char			*gnl_strjoin(char *s1,char *s2);
char			*gnl_strndup(char *str);
int 			find_n(char *str);
/* get_next_line */
int 			get_next_line(int fd, char **line);
/* colors */
int 			trgb(int t, int r, int g, int b);
int 			get_t(int trgb);
int 			get_r(int trgb);
int 			get_g(int trgb);
int 			get_b(int trgb);
/* input_management */
void			printinput(t_scene *scene);
char 			**ft_matdup(char **mat, int dim);
void			get_map(char **str, t_scene *scene);
int 			input_management(t_scene *scene);
/* get_inputs */
int				get_number(char *str);
char			*get_str(char *src);
void			get_resolution(char *str, t_scene *scene);
void			get_floor_color(char *str, t_scene *scene);
void			get_ceiling_color(char *str,t_scene *scene);
/* get_textures */
void			get_north_texture(char *str, t_scene *scene);
void			get_east_texture(char *str, t_scene *scene);
void			get_south_texture(char *str, t_scene *scene);
void			get_west_texture(char *str, t_scene *scene);
void			get_sprite_texture(char *str, t_scene *scene);
/* get_map */
int				map_manager(t_scene *scene);
int				is_map_valid(t_scene *scene);
/* struct_init */
void 			data_init(t_data *data);
void 			win_init(t_win *win);
void 			pc_init(t_pc *pc);
void 			map_init(t_map *map);
void 			scene_init(t_scene *scene);
/* struct_print */
void			print_data(t_data data);
void			print_win(t_win win);
void			print_pc(t_pc pc);
void			print_map(t_map map);
void			print_scene(t_scene scene);
/* raycasting */
void 			raycast(t_scene *scene);
/* utils */
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
int				get_pixel_data(t_data *data, int x, int y);
double			rad(double alpha);
double			pitagora(t_scene *scene, double x, double y);
void	 		angle_fix(double *angle);
void	 		angle_fix_rad(double *angle);
int				ft_abs(int a);
void wall_seen(t_scene *scene, int *wall, int dx, int dy);
double grades(double alpha);

/* hooks */
int				key_hook(int keycode, t_scene *scene);
int 			free_key(int keycode, t_scene *s);
int				mouse_hook(int button, int x, int y, t_scene *scene);
void			move_player(t_scene *scene);
void			rotate_player(t_scene *scene);
void			keymanagement(t_scene *scene);
/* render */
void			render_ceiling(t_scene *scene);
void			render_floor(t_scene *scene);
int				render_next_frame(t_scene *scene);

/* draw_basics */
void drawImgsquare(int x, int y, int dim, int trgb, t_data *data);
void drawImgVertLine(int x, int y, int dim, int trgb, t_data *data);
void drawImgHoriLine(int x, int y, int dim, int trgb, t_data *data);

/* get_texture */
void get_texture(t_scene *scene);
#endif