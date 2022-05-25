# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 14:25:10 by naqua             #+#    #+#              #
#    Updated: 2022/02/28 11:12:44 by naqua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRCS_DIR	= srcs
INCLUDES	= ${SRCS_DIR}/philo.h

SRCS		= ${SRCS_DIR}/philo.c \
			  ${SRCS_DIR}/free.c \
			  ${SRCS_DIR}/actions.c \
			  ${SRCS_DIR}/init.c \
			  ${SRCS_DIR}/process.c \
			  ${SRCS_DIR}/utils.c

OBJS		= ${SRCS:.c=.o}

CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= rm -rf

${NAME}: ${OBJS}
	${CC} ${FLAGS} ${SRCS} -o ${NAME}

all: ${NAME} ${OBJS} ${INCLUDES}

%.o: %.c ${INCLUDES}
	${CC} ${FLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
