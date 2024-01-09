# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:54:56 by igaguila          #+#    #+#              #
#    Updated: 2024/01/09 13:12:54 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = $(wildcard src/*.c src/rules/*.c)

OBJ = ${SRC:.c=.o}

LIBFT = includes/libft/libft.a

PRINTF = includes/ft_printf/ft_printf.a

all: ${NAME}
${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re