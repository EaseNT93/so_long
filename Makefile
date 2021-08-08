NAME = so_long

SRC =	so_long.c\
		get_next_line.c\
		get_next_line_utils.c\
		parse_map.c\
		check_map.c\
		move.c\
		draw_map.c\
		so_long_utils.c\
		textures.c\
		enemy.c

OBJ = $(SRC:.c=.o)

INCLUDE = includes/so_long.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

RM = rm -rf

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit -lm

all: $(NAME)

$(NAME): $(OBJ)
		$(MAKE) -C mlx/
		mv mlx/libmlx.dylib .
		$(CC) $(CFLAGS) $(OBJ) -I $(INCLUDE) $(MLX) libmlx.dylib -o $(NAME)
		
clean:
		$(MAKE) -C mlx clean
		$(RM) $(OBJ)
		
fclean: clean
		$(RM) libmlx.dylib
		$(RM) $(NAME)
		
re: fclean all

.PHONY:	all fclean clean re