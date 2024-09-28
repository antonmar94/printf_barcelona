# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: antonio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/28 13:07:04 by antonio-          #+#    #+#              #
#    Updated: 2024/09/28 13:26:08 by antonio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCDIR = src
HEADERDIR = includes
SRC = $(wildcard $(SRCDIR)/*.c)
SRC_BONUS = 
HEADER = $(wildcard $(HEADERDIR)/*.h)
CC = cc
FLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
MAKENAME = Makefile
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c $(HEADER) $(MAKENAME)
	$(CC) $(FLAGS) -c $< -o $@

bonus: .$(NAME).bonus

.$(NAME).bonus: $(OBJ_BONUS)
	ar rcs $(NAME) $?
	touch $@

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@rm -f $(NAME) .$(NAME).bonus $(OBJ) $(OBJ_BONUS)

re: fclean all bonus

.PHONY: all bonus clean fclean re
