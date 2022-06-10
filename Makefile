NAME		=	minishell

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

FREADLINE	=	-L /Users/kannie/.brew/Cellar/readline/8.1.2/lib -I /Users/kannie/.brew/Cellar/readline/8.1.2/include/ -lreadline
#-ledit
HEADER		=	minishell.h

SRCS		=	minishell.c

OBJS		=	$(SRCS:%.c=%.o)

RM			=	rm -f

${NAME}:	$(OBJS)
			$(CC) $(FREADLINE) $(OBJS) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(FLAGS) -c $< -o $@
			
all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re