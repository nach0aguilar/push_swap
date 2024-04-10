# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 13:54:56 by igaguila          #+#    #+#              #
#    Updated: 2024/04/10 16:19:18 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

SRC = $(wildcard src/*.c src/rules/*.c src/utils/*.c src/sort/*.c)
BONUS_SRC = $(wildcard src/rules/*.c src/utils/*.c src/sort/*.c src/bonus/*.c)

OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${BONUS_SRC:.c=.o}

LIBFT_DIR = includes/libft
PRINTF_DIR = includes/ft_printf
GNL_DIR = includes/get_next_line

LIBFT = ${LIBFT_DIR}/libft.a
PRINTF = ${PRINTF_DIR}/ft_printf.a
GNL = ${GNL_DIR}/get_next_line.a

BONUS_INC = ${LIBFT} ${PRINTF} ${GNL}

all: ${NAME}

bonus: ${BONUS_NAME}

${NAME}: ${OBJ}
	@make -C includes/libft
	@make -C includes/ft_printf
	@make -C includes/get_next_line
	@${CC} ${CFLAGS} ${OBJ} ${LIBFT} ${PRINTF} -o ${NAME}

${BONUS_NAME}: ${OBJ_BONUS}
	@${CC} ${CFLAGS} ${OBJ_BONUS} ${BONUS_INC} -o ${BONUS_NAME}

clean:
	@make -C ${LIBFT_DIR} clean
	@make -C ${PRINTF_DIR} clean
	@make -C ${GNL_DIR} clean
	@${RM} ${OBJ} ${OBJ_BONUS}

fclean: clean
	@make -C ${LIBFT_DIR} fclean
	@make -C ${PRINTF_DIR} fclean
	@make -C ${GNL_DIR} fclean
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY: all clean fclean re bonus