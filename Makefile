# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anoury <anoury@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 19:16:50 by anoury            #+#    #+#              #
#    Updated: 2022/06/01 18:57:31 by anoury           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB1 = ar -rcs
RM = rm -f

INCLUDE = ft_printf.h

SOURCES =	ft_printf.c \
			hexadecimal.c \
			conversion.c \
			decimals.c
OBJECTS =	$(SOURCES:.c=.o)

all: $(NAME)
$(NAME):	$(OBJECTS)	$(INCLUDE)
			$(LIB1)		$(NAME)	$(OBJECTS)
.o: .c
	$(CC) -c $(CFLAGS) $(SOURCES) -I $(INCLUDE) -o $@

clean:
	$(RM)	$(OBJECTS)

fclean: clean
	$(RM)	$(NAME)

re: fclean all

.PHONY: all clean fclean re
