# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igaguila <igaguila@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 16:12:01 by igaguila          #+#    #+#              #
#    Updated: 2024/04/09 16:12:58 by igaguila         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 			= 	get_next_line.c get_next_line_utils.c

OBJS			= 	${SRC:.c=.o}

NAME			= 	get_next_line.a

CC				= 	gcc

CFLAGS			= 	-Wall -Wextra -Werror

RM				= 	rm -f

all: ${NAME}

${NAME}: ${OBJS}
	@ar rcs ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean:
	@${RM} ${OBJS}
	@${RM} ${NAME}

re:	fclean all

.PHONY: all clean fclean re