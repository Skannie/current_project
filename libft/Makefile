# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kannie <kannie@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 19:49:47 by kannie            #+#    #+#              #
#    Updated: 2021/11/15 15:19:49 by kannie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

GCC			=	gcc

FLAG		=	-Wall -Wextra -Werror

LIB			=	libft.h

SRCS		=	ft_isalpha.c ft_isprint.c ft_memset.c  ft_bzero.c \
				ft_isascii.c ft_memcpy.c ft_strlcpy.c ft_isalnum.c \
				ft_isdigit.c ft_memmove.c ft_strlen.c ft_toupper.c \
				ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c \
				ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strlcat.c \
				ft_atoi.c ft_substr.c ft_calloc.c ft_strdup.c \
				ft_strjoin.c ft_strtrim.c ft_striteri.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_strmapi.c ft_itoa.c ft_split.c

OBGS		=	${SRCS:.c=.o}

RM			=	rm -f


all:		${NAME}

${NAME}:	${OBGS} ${LIB}
			ar rc ${NAME} ${OBGS}
			ranlib ${NAME}

${OBGS}:	${LIB}
			${GCC} ${FLAG} -c ${SRCS}

clean:		
			${RM} ${OBGS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re
