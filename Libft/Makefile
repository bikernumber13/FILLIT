# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouhier <mbouhier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 10:53:48 by mbouhier          #+#    #+#              #
#    Updated: 2015/12/29 21:04:22 by mbouhier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = `ls | grep "\.c" | grep "ft_"`

SRCO = `ls | grep "\.o" | grep "ft_"`

all : $(NAME)

$(NAME) :
		@gcc -Wall -Wextra -Werror -I. -c $(SRC)
		@ar rc $(NAME) $(SRCO)
		@ranlib $(NAME)

clean :
		@rm -f $(SRCO)

fclean : clean
		@rm -f $(NAME)

re : fclean all
