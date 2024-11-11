NAME			= rush-02 
MKDIR			= mkdir -p
CC				= cc
INCLUDES 		= -Iincludes
CFLAGS			= -Wall -Wextra -Werror -g
SRCS_DIR		= srcs
SRCS			= $(wildcard $(SRCS_DIR)/*.c)
OBJS_DIR		= objs
OBJS			= $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)) 
RM				= rm -rf

all : $(NAME)

$(NAME) : $(OBJS)
	@echo " - Compiling $(NAME)..."
	@gcc $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo " - Compiling FINISHED"

$(OBJS_DIR)/%.o : $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

clean :
	@$(RM) $(OBJS_DIR)

fclean : clean
	@$(RM) $(NAME)
	@echo  $(RED) " - Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
