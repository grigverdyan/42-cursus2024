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

HEADERS_DIR		= headers
HEADERS_FLAG	= -I$(HEADERS_DIR) -I$(LIBFT_DIR)
HEADERS			= $(wildcard $(HEADERS_DIR)/*.h) $(LIBFT_DIR)/libft.h

SOURCES_DIR		= sources/
SOURCE_FILES	= main.c

SOURCES			= $(addprefix $(SOURCES_DIR), $(SOURCE_FILES))

OBJS_DIR		= objs/
OBJ_FILES		= $(SOURCE_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

LINKER			= -lft -L $(LIBFT_DIR)


ifeq ($(OS), Linux)
		MLX_DIR		= mlx_linux/
		LINKER		+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
else
		MLX_DIR		= mlx_macos/
		LINKER		+= -lmlx -lm -framework OpenGl -framework Appkit -L $(MLX_DIR)
endif

HEADERS_FLAG			+= -I$(MLX_DIR)
MLX_A			= libmlx.a
MLX				= $(addprefix $(MLX_DIR), $(MLX_A))


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
	@$(CC) $(CFLAGS) $(HEADERS_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(TARGET)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) "  Removing Libft, MiniLibX and $(TARGET)" $(RESET)

re : fclean all
