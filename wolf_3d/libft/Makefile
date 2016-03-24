# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollet <acollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/05 21:17:10 by acollet           #+#    #+#              #
#    Updated: 2015/05/07 08:26:50 by acollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_atoi.c \
	   ft_bzero.c \
	   ft_ceil.c \
	   ft_fabs.c \
	   ft_floor.c \
	   ft_htoa.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_lstadd.c \
	   ft_lstaddqueue.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstinsert.c \
	   ft_lstiter.c \
	   ft_lstlast.c \
	   ft_lstlen.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_lstsort.c \
	   ft_lstswap.c \
	   ft_lstprevious.c \
	   ft_lstrevert.c \
	   ft_memalloc.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memdel.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_ntoa.c \
	   ft_otoa.c \
	   ft_pow.c \
	   ft_putchar.c \
	   ft_putendl.c \
	   ft_putnbr.c \
	   ft_putstr.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_sqrt.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_strclr.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdel.c \
	   ft_strdup.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strmove.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strnew.c \
	   ft_strnstr.c \
	   ft_strpos.c \
	   ft_strrchr.c \
	   ft_strsplit.c \
	   ft_strstr.c \
	   ft_strsub.c \
	   ft_strtoupper.c \
	   ft_strtolower.c \
	   ft_strtrim.c \
	   ft_strconcat.c \
	   ft_swapfloat.c \
	   ft_tolower.c \
	   ft_toupper.c

OBJS = $(patsubst %.c, %.o, $(SRCS))

LBLUE	= \033[1;34m
LGREEN	= \033[1;32m
NC		= \033[0m

.PHONY: all $(NAME) norme clean fclean re
 
all: prefix $(NAME) suffix

$(NAME): $(OBJS)
	@ar rc $@ $(OBJS)
	@ranlib $(NAME)

%.o: %.c
	@echo "-\c"
	@gcc $(CFLAGS) -I ./includes/ -c -o $@ $^

norme:
	@norminette $(SRCS) ./includes/libft.h

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

prefix:
	@echo "$(LBLUE)Compilation de la libft$(NC) ... [$(LGREEN)\c"

suffix:
	@echo "$(NC)]\t[$(LGREEN)OK$(NC)]"