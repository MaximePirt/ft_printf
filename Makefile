# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpierrot <mpierrot@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 20:31:37 by mpierrot          #+#    #+#              #
#    Updated: 2024/02/06 12:35:41 by mpierrot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDRDIR   = includes
SRCDIR   = srcs
OBJDIR   = objs

SRCS     = srcs/ft_printf.c \
			srcs/ft_usefulfonc.c \
			srcs/libft_functions.c \
			srcs/ft_putptrfunc.c
OBJS     = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
NAME     = libftprintf.a
CC       = clang
CFLAGS   = -Wall -Wextra -Werror
RM       = rm -rf
AR       = ar rcs

DEFCOLOR = \033[0;39m
GREEN    = \033[0;92m
YELLOW   = \033[0;93m
BLUE     = \033[0;94m
CYAN     = \033[0;96m

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)ft_printf has been successfully compiled$(DEFCOLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@echo "$(YELLOW)Compiling: $< $(DEFCOLOR)"
	@$(CC) $(CFLAGS) -I $(HDRDIR) -c $< -o $@

clean:
	@$(RM) objs
	@echo "$(BLUE)ft_printf object files cleaned!$(DEFCOLOR)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(CYAN)ft_printf executable has been cleaned!$(DEFCOLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt successfully!$(DEFCOLOR)"

.PHONY: all clean fclean re
