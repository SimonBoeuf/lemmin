CC			= gcc

NAME		= lemmin

INCLUDE		= ./includes/

SRCS		= 	main.c				\
				lemmin.c			\
				ft_get_next_line.c	\
				line_handle.c		\
				anthill.c			\
				room.c				\
				map_to_room.c		\
				pipe.c				\
				str_check.c			\
				paths.c				\
				path.c				\
				ant.c				\

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -g

CLFLAGS     += -L libft -lft
LDFLAGS 	= -I $(DIR_LIBFT)/includes

DIR_LIBFT	= ./libft

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -I $(INCLUDE) -L -lft

$(NAME):	$(DIR_LIBFT)/libft.a $(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CLFLAGS) $(CFLAGS) $(LDFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

$(DIR_LIBFT)/libft.a:
	make  -f Makefile -C $(DIR_LIBFT)

re:			fclean all

.PHONY:		all clean re fclean
