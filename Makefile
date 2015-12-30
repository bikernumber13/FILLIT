# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 14:39:23 by mbouhier          #+#    #+#              #
#    Updated: 2015/12/30 11:28:35 by mbouhier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_PATH = ./srcs/
INCLUDES_PATH = ./includes/

NAME = fillit

FLAGS = -Werror -Wextra -Wall

SRCS_NAME = main.c ft_check.c ft_getcoord.c ft_grid.c ft_printgrid.c ft_read.c \
	ft_solve.c ft_solve2.c

OBJ_NAME = $(SRCS_NAME.c=.o)

SRC = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
INC = $(addprefix -I, $(INCLUDES_PATH))

all : $(NAME)

$(NAME) :
	@echo "\033[32m"
	@echo " ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄  ▄            ▄            ▄▄▄▄▄▄▄▄▄▄▄  ▄▄▄▄▄▄▄▄▄▄▄ "
	@echo "▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░▌          ▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌"
	@echo "▐░█▀▀▀▀▀▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ ▐░▌          ▐░▌           ▀▀▀▀█░█▀▀▀▀  ▀▀▀▀█░█▀▀▀▀ "
	@echo "▐░▌               ▐░▌     ▐░▌          ▐░▌               ▐░▌          ▐░▌     "
	@echo "▐░█▄▄▄▄▄▄▄▄▄      ▐░▌     ▐░▌          ▐░▌               ▐░▌          ▐░▌     "
	@echo "▐░░░░░░░░░░░▌     ▐░▌     ▐░▌          ▐░▌               ▐░▌          ▐░▌     "
	@echo "▐░█▀▀▀▀▀▀▀▀▀      ▐░▌     ▐░▌          ▐░▌               ▐░▌          ▐░▌     "
	@echo "▐░▌               ▐░▌     ▐░▌          ▐░▌               ▐░▌          ▐░▌     "
	@echo "▐░▌           ▄▄▄▄█░█▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄ ▐░█▄▄▄▄▄▄▄▄▄  ▄▄▄▄█░█▄▄▄▄      ▐░▌     "
	@echo "▐░▌          ▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌▐░░░░░░░░░░░▌     ▐░▌     "
	@echo " ▀            ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀  ▀▀▀▀▀▀▀▀▀▀▀       ▀      "
	@echo "                                                                              "
	@echo "\033[0m"
	@make -C libft/
	@gcc $(FLAGS) -L./libft/ -lft $(SRC) $(INC) -o $(NAME) ./libft/libft.a $(OBJ_NAME)

clean :
	@rm -f $(OBJ_NAME)
	@make clean -C libft/

fclean : clean
	@rm -f $(NAME)
	@make fclean -C libft/

re : fclean all

.PHONY: all clean fclean re
