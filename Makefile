# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aali-mou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 21:11:27 by aali-mou          #+#    #+#              #
#    Updated: 2019/10/28 18:31:10 by aali-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = *.c

OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	echo $(NAME) Created;

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)
bonus:
	echo"null"
re: fclean all
