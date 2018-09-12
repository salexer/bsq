# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgaitan <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/24 23:11:33 by pgaitan           #+#    #+#              #
#    Updated: 2016/07/25 20:26:25 by pgaitan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

all:
	@gcc -Wall -Wextra -Werror -c  bsq.c bsq_reader.c bsq_list.c bsq_init.c libft.c
	@gcc -Wall -Wextra -Werror -o $(NAME) bsq.o bsq_reader.o bsq_list.o bsq_init.o libft.o

clean:
	@rm -f bsq.o bsq_reader.o bsq_list.o bsq_init.o libft.o

fclean: clean
	@rm -f $(NAME)

re: clean all
