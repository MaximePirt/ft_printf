# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:31:37 by mpierrot          #+#    #+#              #
#    Updated: 2023/11/23 20:43:01 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c \
       conversion_c.c \
       conversion_s.c \
       conversion_p.c \
       conversion_d.c \
       conversion_u.c \
       conversion_x.c \
       conversion_percent.c \
       utils.c

OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $@ $^
	@echo "$(NAME) has been created successfully."

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	@echo "Object files have been removed."

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) has been removed."

re: fclean all

.PHONY: all clean fclean re
