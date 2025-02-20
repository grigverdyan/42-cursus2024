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

# Target and instructions
TARGET			= materia
CC				= c++
CFLAGS			= -Wall -Wextra -Werror -std=c++98 -g
MKDIR			= mkdir -p
RM				= rm -rf

# Includes
INCLUDE_DIR 	= includes
INCLUDES		= -I$(INCLUDE_DIR)

# Sources
SRC_DIR			= src
SRC_FILES 		= $(shell find $(SRC_DIR) -name "*.cpp")

# Object files
OBJ_DIR			= objs
OBJS 			= $(SRC_FILES:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

all : $(OBJ_DIR) $(TARGET)

$(OBJ_DIR) :
	@$(MKDIR) $(OBJ_DIR)

$(TARGET) : $(OBJS)
	@echo $(GREEN) "Creating $(TARGET)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
	@echo $(YELLOW) "$(TARGET) created." $(RESET)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean :
	@$(RM) $(OBJ_DIR)
	@echo $(RED) "Object files cleaned." $(RESET)

fclean : clean
	@$(RM) $(TARGET)
	@echo $(RED) "$(TARGET) cleaned." $(RESET)

re: fclean all

.PHONY: all clean fclean re
