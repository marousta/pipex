# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marousta <marousta@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/17 13:04:30 by marousta          #+#    #+#              #
#    Updated: 2021/09/04 20:24:44 by marousta         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

#Fork of https://git.42l.fr/jorun/superlibft/src/branch/master/Makefile

SHELL		= /bin/bash

BLACK		= $(shell tput -Txterm setaf 0)
RED			= $(shell tput -Txterm setaf 1)
GREEN		= $(shell tput -Txterm setaf 2)
YELLOW		= $(shell tput -Txterm setaf 3)
LIGHTPURPLE	= $(shell tput -Txterm setaf 4)
PURPLE		= $(shell tput -Txterm setaf 5)
BLUE		= $(shell tput -Txterm setaf 6)
WHITE		= $(shell tput -Txterm setaf 7)
BOLD		= $(shell tput bold)
NORMAL		= $(shell tput sgr0)
ERASE		= "\r\033[K"

TOTAL_BUILD				= ${words srcs}
TOTAL_BUILT				= 0
TOTAL_PERCENTAGE_RAW	= ${TOTAL_BUILT} * 100 / ${TOTAL_BUILD}
TOTAL_PERCENTAGE		= ${shell echo $$(( ${TOTAL_PERCENTAGE_RAW} ))}

###############

NAME		= pipex
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

DIR_OBJS	= .objs
INCLUDES	= includes

SRCS		=	srcs/ft_strlen.c \
				srcs/ft_memset.c	\
				srcs/ft_calloc.c	\
				srcs/ft_substr.c	\
				srcs/ft_split.c	\
				srcs/ft_strjoin.c \
				srcs/file.c	\
				srcs/find_exec.c	\
				srcs/main.c	\

DIR_SRCS	= ${SRCS}

OBJS		= ${SRCS:%.c=${DIR_OBJS}/%.o}

###############

${DIR_OBJS}/%.o:%.c
	@printf "\r%s\n" "[${YELLOW}Infos${NORMAL}] ${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@"
	@printf "\033[K%s" "${PURPLE}${BOLD}[ $(TOTAL_PERCENTAGE)% ]	${NORMAL}${WHITE}Building ${GREEN}$@ ${NORMAL}"
	@${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@
	${eval TOTAL_BUILT=${shell echo $$(( ${TOTAL_BUILT} + 1))}}

all: make_dir ${NAME}

make_dir:
	@mkdir -p ${DIR_OBJS}
	@mkdir -p ${shell find srcs -type d -exec echo ".objs/"{} \;}

debug:
	@echo ${SRCS}
	@echo ${OBJS}

${NAME}: ${OBJS}
	@printf "\r%s\n" "[${YELLOW}Infos${NORMAL}] ${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o ${NAME}"
	@printf "%s\n" "${PURPLE}${BOLD}[ $(TOTAL_PERCENTAGE)% ] ${WHITE}${NAME}: ${BOLD}${GREEN}Building executable ${NORMAL}"
	@${CC} ${CFLAGS} -I ${INCLUDES} ${OBJS} -o ${NAME}
	@printf "\r\033[K%s" "${PURPLE}${BOLD}[ $(TOTAL_PERCENTAGE)% ] ${WHITE}${NAME}: ${BOLD}${GREEN}Build succeeded ${NORMAL}"
	@sleep 0.25
	@printf "\r\033[K%s\n" "${WHITE}${NAME}: ${BOLD}${GREEN}ready ${NORMAL}"

clean:
	@find .objs -exec printf "%s\n" "[${RED}Deleting${NORMAL}] {}" \; | tac
	@rm -rf ${DIR_OBJS}

fclean:	clean
	@printf "%s\n" "[${RED}Deleting${NORMAL}] ${NAME} "
	@rm -f ${NAME}
	@printf "\r\033[K"
	@printf "${NORMAL}"

re: fclean all

.PHONY: all clean fclean re
