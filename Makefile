# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:01:41 by lfreydie          #+#    #+#              #
#    Updated: 2023/02/20 17:52:55 by lfreydie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror -g

INCLUDE = -I includes/

SRC_DIR = src

RM = rm -f

NAME = push_swap

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
PINK=\033[0;35m
END=\033[0m

_SRC = algo.c free.c init.c main.c \
	mouvs_push.c mouvs_rev_rot.c mouvs_rotate.c mouvs_swap.c \
	test.c utils_lst_mv.c utils_lst.c utils.c \
	count_mv.c push_a.c push_b.c

SRC = $(addprefix $(SRC_DIR)/, $(_SRC))

OBJ = $(SRC:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN) ==== Project compiled ==== $(END)"

all :	$(NAME)

clean :
	@$(RM) $(OBJ)
	@echo "$(RED) ==== All object removed ==== $(END)"

fclean :	clean
	@$(RM) $(NAME)
	@echo "$(PINK) ==== Executables removed ==== $(END)"

re :	fclean all

.PHONY : all clean fclean re
