# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samercad <samercad@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/04 19:35:44 by samercad          #+#    #+#              #
#    Updated: 2026/11/04 20:23:39 by samercad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

FILES	= ft_printf.c print_handler.c print_logic.c

OBJS	= $(FILES:.c=.o)

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(OBJS):	ft_printf.h

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean
		$(MAKE) all

.PHONY:	all clean fclean re
