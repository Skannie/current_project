NAME		=	minishell

LIBFT		=	libft/libft.a

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

FREADLINE	=	-L /Users/kannie/.brew/Cellar/readline/8.1.2/lib -I /Users/kannie/.brew/Cellar/readline/8.1.2/include/ -lreadline
#-ledit
HEADER		=	minishell.h

SRCS		=	minishell.c

OBJS		=	$(SRCS:%.c=%.o)

RM			=	rm -f

${NAME}:	$(OBJS)
			make -C ./libft
			$(CC) $(FREADLINE) $(LIBFT) $(OBJS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@
			
all:		$(NAME)

clean:		
			$(RM) $(OBJS)
			make clean -C ./libft

fclean:		clean
			$(RM) $(NAME)
			make fclean -C ./libft

re:			fclean all

.PHONY: all clean fclean re