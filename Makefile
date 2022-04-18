NAME		=	philo

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror

HEADER		=	philo.h

SRCS		=	philo.c philo_utils.c

OBJS		=	${SRCS:%.c=%.o}

RM			=	rm -f

${NAME}:	$(OBJS)
			$(CC) $(OBJS) -o $(NAME)

%.o:		%.c
			$(CC) ${FLAGS} -c $< -o $@
			
all:		${NAME}

clean:		
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re