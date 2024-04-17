.PHONY : all clean fclean re

TARGET			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

RM				= rm -rf
MKDIR			= mkdir -p
OS				= $(shell uname)
MAKE			= make -sC


LIBFT_DIR		= libft/
LIBFT_A			= libft.a
LIBFT			= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

HEADERS			= -Iheaders -I$(LIBFT_DIR)

SOURCES_DIR		= sources/
SOURCES			= $(wildcard $(SOURCES_DIR)/*.c)

OBJS_DIR		= objs
OBJS_FILES		= $(SOURCES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

LINKER			= -lft -L $(LIBFT_DIR)

MLX_A			= libmlx.a

ifeq ($(OS), Linux)
		MLX_DIR		= mlx_linux/
		LINKER		+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
else
		MLX_DIR		= mlx_macos/
		LINKER		+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
endif

HEADERS		+= -I$(MLX_DIR)
MLX			= $(addprefix $(MLX_DIR), $(MLX_A))


# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

all : $(LIBFT) $(MLX) $(OBJS_DIR) $(TARGET)

$(LIBFT) :
	@echo $(BLUE) "  Creating Libft" $(RESET)
	@$(MAKE) $(LIBFT_DIR)

$(MLX) :
	@echo $(YELLOW) "  Creating MiniLibX" $(RESET)
	@$(MAKE) $(MLX_DIR)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(TARGET) : $(OBJS) Makefile
	@echo $(GREEN) "  Creating $(TARGET)" $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(TARGET)

$(OBJS_DIR)%.o : $(SOURCES_DIR)%.c $(HEADERS)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(TARGET)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) "  Removing Libft, MiniLibX and $(TARGET)" $(RESET)

re : fclean all
