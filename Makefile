# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 15:01:41 by lfreydie          #+#    #+#              #
#    Updated: 2023/02/23 19:33:38 by lfreydie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDE = -I includes/

SRC_DIR = src

BONUS_DIR = bonus

RM = rm -f

NAME = push_swap

NAME_B = checker

# Colors
GREEN=\033[0;32m
RED=\033[0;31m
PINK=\033[0;35m
END=\033[0m

SRC = $(shell find $(SRC_DIR) -type f -name *.c)

SRC_B = $(shell find $(BONUS_DIR) -type f -name *.c)

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ)
	@$(CC) -o $(NAME) $(OBJ)
	@echo "$(GREEN) ==== Project compiled ==== $(END)"

all :	$(NAME)

bonus :	$(OBJ_B)
	@$(CC) -o $(NAME_B) $(OBJ_B)
	@echo "$(GREEN) ==== Bonus compiled ==== $(END)"

clean :
	@$(RM) $(OBJ) $(OBJ_B)
	@echo "$(RED) ==== All object removed ==== $(END)"

fclean :	clean
	@$(RM) $(NAME) $(NAME_B)
	@echo "$(PINK) ==== Executables removed ==== $(END)"

re :	fclean all

.PHONY : all clean fclean re
