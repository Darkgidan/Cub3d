NAME	=	cub3d
LIBFT	=	./libft/libft.a
CC		=	gcc
CFLAGS	=
RM		=	rm -f
LIBS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit -lm
MLX		=	libmlx.dylib
SRCS	=	cub3d.c \
			colors.c \
			get_inputs.c \
			get_map.c \
			get_textures.c \
			input_management.c \
			get_next_line.c \
			get_next_line_utils.c \
			struct_init.c \
			struct_print.c \
			raycasting.c \
			utils.c \
			renders.c \
			hooks.c \
			movement.c \
			draw_basics.c \
			get_texture.c

OBJ		=	$(SRCS:.c=.o)

%.o	:	%.c
			$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME)	:	$(MLX) $(OBJ)
			make bonus -C ./libft
			$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(OBJ) $(LIBS)

$(MLX)	:
			@$(MAKE) -C mlx
			@mv mlx/$(MLX) .

all		:	$(NAME)

comp :
	gcc *.c libft/*.c libft/*.h libmlx.dylib
	./a.out | cat -e

clean	:
			make -C mlx clean
			$(RM) $(OBJ)
			make clean -C ./libft

fclean	:	clean
			$(RM) $(NAME) $(MLX)
			make fclean -C ./libft

re		:	fclean all

.PHONY	:	all clean fclean re comp