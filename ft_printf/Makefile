NAME = libftprintf.a

CC = cc

INCLUDES = -Iincludes

CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard srcs/*.c)

OBJS = $(patsubst %.c, %.o, $(SRCS))

AR = ar rcs

RM = rm -f

CP = cp

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all libft clean fclean re
