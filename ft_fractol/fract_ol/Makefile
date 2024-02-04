NAME = fractol

OS = $(shell uname)

CC = cc

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

OBJ_PATH = objs

HEADER = includes

SRC_PATH = srcs

ifeq ($(OS), Linux)
	MLX = mlx_linux
	LINKER = -lft -lmlx -lm -lXext -lX11
else
	MLX = mlx_macos
	LINKER = -lft -lmlx -lm -framework OpenGL -framework Appkit
endif

SRC_FILES = hooks.c \
			color.c \
			julia.c \
			utils.c \
			buffalo.c \
			tricorn.c \
			fractol.c \
			helpers.c \
			parsing.c \
			mandelbrot.c \
			burning_ship.c \
			celtic_mandelbar.c \
			heart_mandelbrot.c \
			celtic_mandelbrot.c \
			burning_ship_fifth.c \
			perpendicular_burning_ship.c

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJS = $(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

all: lib tmp $(NAME)

lib:
	@$(MAKE) -s -C $(LIBFT)
	@$(MAKE) -s -C $(MLX)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ $(LINKER)

tmp:
	@mkdir -p objs

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
	@$(CC) $(FLAGS) -c -o $@ $<

clean:
	@$(MAKE) -s clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C $(LIBFT)

re: fclean
	@$(MAKE) -s all

.PHONY: all, clean, fclean, re, tmp
