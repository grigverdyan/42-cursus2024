CLIENT			= client
SERVER			= server
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g

SRCS			= $(wildcard *.c)
OBJS_DIR		= objs
OBJS			= $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
FT_PRINTF_DIR	= ft_printf/
FT_PRINTF_A		= libftprintf.a
FT_PRINTF		= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))
RM				= rm -rf
MKDIR			= mkdir -p

all : $(CLIENT) $(SERVER)

client : $(CLIENT)

$(CLIENT) : $(OBJS_ClIENT)
