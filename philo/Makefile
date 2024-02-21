# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ebmarque <ebmarque@student.42porto.com     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/06 14:47:38 by ebmarque          #+#    #+#              #
#    Updated: 2024/02/21 18:15:16 by ebmarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -fsanitize=address
NAME = philo

SRC =  SRC/UTILS/utils_1.c SRC/UTILS/utils_2.c SRC/ERROR/*.c \
		SRC/INIT/init.c SRC/INIT/init_2.c SRC/SIMULATION/simulation.c \
		SRC/SIMULATION/main.c SRC/SIMULATION/actions.c \
		SRC/UTILS/utils_3.c SRC/SIMULATION/monitoring.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
