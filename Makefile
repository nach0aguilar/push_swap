# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:54:56 by igaguila          #+#    #+#              #
#    Updated: 2024/01/16 10:45:11 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

SRC = $(wildcard src/*.c src/rules/*.c)

OBJ = ${SRC:.c=.o}

LIBFT_DIR = includes/libft

PRINTF_DIR = includes/ft_printf

LIBFT = includes/libft/libft.a

PRINTF = includes/ft_printf/ft_printf.a

all: ${NAME}
${NAME}: ${OBJ}
	@make -C includes/libft
	@make -C includes/ft_printf
	${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	${RM} ${OBJ}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re