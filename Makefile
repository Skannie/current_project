NAME		=	minishell

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

FREADLINE	=	-L /Users/kannie/.brew/Cellar/readline/8.1.2/lib -I /Users/kannie/.brew/Cellar/readline/8.1.2/include/ -lreadline
#-ledit
HEADER		=	minishell.h

SRCS		=	minishell.c readstr.c

LIBFT		=	libft/libft.a

OBJS		=	$(SRCS:%.c=%.o)

RM			=	rm -f

${NAME}:	$(OBJS)
			make -C ./libft
			$(CC) $(FREADLINE) $(OBJS) $(LIBFT) -fsanitize=address -o $(NAME)

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