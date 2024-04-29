.PHONY : all clean fclean re

SERVER			= server
CLIENT			= client
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
RM				= rm -rf
MKDIR			= mkdir -p

FT_PRINTF_DIR	= ft_printf/
FT_PRINTF_A		= libftprintf.a
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))

LIBFT_DIR	= libft/
LIBFT_A		= libftprintf.a
LIBFT		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))

HEADERS_FLAG	= -I$(FT_PRINTF_DIR)
HEADERS			= $(FT_PRINTF_DIR)/ft_printf.h

SERVER_FILES	= server.c
CLIENT_FILES	= client.c

SERVER_OBJS			= $(SERVER_FILES:.c=.o)
CLIENT_OBJS			= $(CLIENT_FILES:.c=.o)

LINKER				= -lftprintf -L $(FT_PRINTF_DIR)

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

all : $(CLIENT) #$(SERVER) 

$(SERVER) : $(SERVER_OBJS)
	@echo $(GREEN) "  Creating $(SERVER)" $(RESET)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LINKER) -o $(SERVER)	

$(CLIENT) : $(CLIENT_OBJS)
	@echo $(GREEN) "  Creating $(CLIENT)" $(RESET)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LINKER) -o $(CLIENT)	

%.o : %.c
	@$(CC) $(CFLAGS) $(HEADERS_FLAG) -c $< -o $@

clean :
	@$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
	@echo $(MAGENTA) "  Removing Object Files" $(RESET)

fclean : clean
	@$(RM) $(SERVER) $(CLIENT)
	@echo $(RED) "  Removing $(SERVER) and $(CLIENT)" $(RESET)

re : fclean all
