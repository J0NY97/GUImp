NAME = libui.a
SRCS = ft_test_libui.c
OBJS = $(SRCS:.c=.o)
LIBS = libui.h
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) $(LIBS) $(FLAGS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean, all, fclean, re
