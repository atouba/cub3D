NAME				=	cub3D

CC = cc -Wall -Werror -Wextra
MLX_FLAGS = -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit 

RM					=	rm -rf

LIBFT_DIR			=	libft
LIBFT_NAME			=	libft/libft.a

GET_NEXT_LINE_DIR	= get_next_line

all: $(NAME)

FILES				=	main.c											\
						$(GET_NEXT_LINE_DIR)/get_next_line.c			\
						$(GET_NEXT_LINE_DIR)/get_next_line_utils.c		\
						parsing/parse.c									\
						parsing/file_x_map.c							\
						parsing/arguments_checker.c						\
						parsing/file_checker.c							\
						parsing/file_checker_2.c 						\
						parsing/file_checker_3.c 						\
						parsing/file_checker_4.c 						\
						parsing/file_checker_5.c 						\
						draw/map_dimensions.c							\
						draw/draw_minimap_and_player_movements.c		\
						draw/emit_rays.c								\
						dda.c											\
						dda_functions.c									\
						init.c											\
						mlx_put_get.c									\
						draw/emit_rays_utils.c

OBJS		=	$(FILES:.c=.o)

$(LIBFT_NAME):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_NAME) $(MLX_FLAGS) -o $(NAME)

clean:
	$(RM) *.o
	make clean -C $(LIBFT_DIR)
	cd $(PARSING_DIR) && $(RM) *.o
	cd $(EXECUTION_DIR) && $(RM) *.o

fclean: clean
	$(RM) $(NAME) ${OBJS}
	make fclean -C $(LIBFT_DIR)

re: fclean all
