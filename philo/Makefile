# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/23 12:28:28 by ebmarque          #+#    #+#              #
#    Updated: 2024/02/25 19:12:25 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

NAME = philo

CORE_CODE =			src/core_code/main.c src/core_code/simulation.c \
					src/core_code/actions.c

INITIALIZATION = 	src/initialization/data_initialization.c \
					src/initialization/init_simulation.c
					
TOOLS =				src/tools/input_validation.c \
					src/tools/utils_1.c \
					src/tools/utils_2.c \
					src/tools/utils_3.c

SRCS = $(CORE_CODE) $(INITIALIZATION) $(TOOLS)
OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #