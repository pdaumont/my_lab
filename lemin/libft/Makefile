# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdaumont <pdaumont@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:11:15 by pdaumont          #+#    #+#              #
#    Updated: 2015/02/26 17:42:33 by pdaumont         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

MEM = ./Mem/ft_memccpy.c ./Mem/ft_memchr.c ./Mem/ft_memcmp.c ./Mem/ft_memcpy.c ./Mem/ft_memmove.c ./Mem/ft_memset.c ./Mem/ft_bzero.c ./Mem/ft_memalloc.c ./Mem/ft_memdel.c

IS = ./Is/ft_isalnum.c ./Is/ft_isalpha.c ./Is/ft_isascii.c ./Is/ft_isdigit.c ./Is/ft_isprint.c ./Is/ft_atoi.c ./Is/ft_itoa.c

STR = ./Str/ft_strcat.c ./Str/ft_strchr.c ./Str/ft_strcmp.c ./Str/ft_strcpy.c ./Str/ft_strdup.c ./Str/ft_strlcat.c ./Str/ft_strlen.c ./Str/ft_strncat.c ./Str/ft_strncmp.c ./Str/ft_strncpy.c ./Str/ft_strnstr.c ./Str/ft_strrchr.c ./Str/ft_strstr.c ./Str/ft_strclr.c ./Str/ft_strdel.c ./Str/ft_strequ.c ./Str/ft_striter.c ./Str/ft_striteri.c ./Str/ft_strjoin.c ./Str/ft_strmap.c ./Str/ft_strmapi.c ./Str/ft_strnequ.c ./Str/ft_strnew.c ./Str/ft_strsplit.c ./Str/ft_strsub.c ./Str/ft_strtrim.c ./Str/ft_strpos.c ./Str/ft_strmove.c ./Str/ft_strconcat.c

PUT = ./Put/ft_putchar.c ./Put/ft_putendl.c ./Put/ft_putnbr.c ./Put/ft_putstr.c ./Put/ft_putchar_fd.c ./Put/ft_putendl_fd.c ./Put/ft_putnbr_fd.c ./Put/ft_putstr_fd.c

TO = ./Str/ft_tolower.c ./Str/ft_toupper.c

LST = ./Lst/ft_lstadd.c ./Lst/ft_lstaddchemins.c ./Lst/ft_lstaddqueue.c ./Lst/ft_lstdel.c ./Lst/ft_lstdelone.c ./Lst/ft_lstinsert.c ./Lst/ft_lstiter.c ./Lst/ft_lstlast.c ./Lst/ft_lstlen.c ./Lst/ft_putlst.c\
./Lst/ft_lstmap.c ./Lst/ft_lstnew.c ./Lst/ft_lstnewchemins.c ./Lst/ft_lstprevious.c ./Lst/ft_lstrevert.c ./Lst/ft_lstswap.c

NUM = ./Num/ft_pow.c

TREE = ./Tree/addnode.c ./Tree/clear_tree.c ./Tree/print_reverse_tree.c ./Tree/print_tree.c ./Tree/search_node.c

SRC = $(MEM) $(IS) $(STR) $(PUT) $(TO) $(NUM) $(LST) $(TREE)

OBJ = *.o

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c $(SRC) -I ./includes/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
