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

# Compiler
EXEC			= minishell
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror #-MMD -MP
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

# Includes
INCLUDE_DIR 	= include
INCLUDES		= -I$(INCLUDE_DIR)

# Sources
SRC_DIR			= src
SRC_FILES 		= $(shell find src -name "*.c")

# Libft
LIB_DIR			= lib
LIBFT_DIR		= $(LIB_DIR)/libft
LIBFT			= $(LIBFT_DIR)/libft.a
INCLUDES		+= -I$(LIBFT_DIR)
LDLIBS  	    = -lft -L$(LIBFT_DIR)

# Readline
RL_DIR			= $(LIB_DIR)/readline
RL_BUILD_DIR	= $(LIB_DIR)/rl_lib
INCLUDES		+= -I$(RL_BUILD_DIR)/include
LDLIBS			+= -lreadline -L$(RL_BUILD_DIR)/lib

# Object files
OBJ_DIR			= objs
OBJS 			= $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Dependencies
#DEPS 			= $(patsubst %.o, %.d, $(OBJS))
#-include		$(DEPS)


all : $(LIBFT) $(RL_BUILD_DIR) $(OBJ_DIR) $(EXEC)

$(LIBFT) :
	@echo $(CYAN) " - Making libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) " - Made libft!" $(RESET)

$(RL_BUILD_DIR):
	@echo $(CYAN) " - Making readline..." $(RESET)
	@bash $(RL_DIR)/rl_build.sh
	@echo $(YELLOW) " - Made readline!" $(RESET)

$(OBJ_DIR) :
	@$(MKDIR) $(OBJ_DIR)

$(EXEC) : $(OBJS) Makefile
	@echo $(GREEN) " - Compiling $(EXEC)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LDLIBS) -o $(EXEC) 
	@echo $(YELLOW) " - Compiling FINISHED" $(RESET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@$(RM) $(OBJ_DIR)
	@echo $(RED) " - Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(EXEC)
	@rm -rf $(RL_BUILD_DIR)
	@make distclean -C lib/readline
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) " - Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
