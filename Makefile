# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:54:56 by igaguila          #+#    #+#              #
#    Updated: 2024/01/21 17:34:53 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = $(wildcard src/*.c src/rules/*.c src/utils/*.c src/sort/*.c)
OBJ = ${SRC:.c=.o}

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf

LIBFT = ${LIBFT_DIR}/libft.a
PRINTF = ${PRINTF_DIR}/ft_printf.a

all: ${NAME}
${NAME}: ${OBJ}
	@make -C includes/libft
	@make -C includes/ft_printf
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@${RM} ${OBJ}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re