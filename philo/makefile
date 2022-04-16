# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abellakr <abellakr@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/16 15:24:59 by abellakr          #+#    #+#              #
#    Updated: 2022/04/16 17:07:24 by abellakr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFlAGS = -Wall -Wextra -Werror

SRC = philo.c utils.c ft_atoi.c
OBJ = $(SRC:.c=.o)

all : $(NAME)
%.o:%.c
	@$(CC) $(CFlAGS) -c $<
$(NAME) : $(OBJ)
	@$(CC) $(CFlAGS) $(OBJ) -o $(NAME)
clean : 
	@rm -f $(OBJ)
fclean : clean
	@rm -f $(NAME)
re : fclean all
.PHONY : clean fclean bonus re
