# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acollet <acollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/29 11:03:26 by acollet           #+#    #+#              #
#    Updated: 2015/05/07 14:43:54 by acollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef DBUG
	CFLAGS = -Wall -Werror -Wextra
endif

NAME = wolf3d
SRC =  wolf.c \
	   events.c \
	   file.c \
	   get_next_line.c \
	   raycast.c \
	   bresenham.c \
	   draw.c \
	   action.c
			
OBJ = $(SRC:.c=.o)

SRCDIR 	= ./srcs/
INCDIR 	= ./includes/
LIBDIR	= ./libft
MLXDIR	= ./minilibx_macos
OBJDIR  = ./objs/

SRCS   	= $(addprefix $(SRCDIR), $(SRC))
OBJS   	= $(addprefix $(OBJDIR), $(OBJ))

LIBFLAGS = -L$(LIBDIR) -lft -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit

LBLUE	= \033[1;34m
LGREEN	= \033[1;32m
NC		= \033[0m

.PHONY : all lib norne clean fclean re

all: mlx lib prefix $(NAME)

$(NAME): $(OBJS)
	@gcc $(FLAGS) $(LIBFLAGS) -o $(NAME) $(OBJS)
	@echo "$(LBLUE)$(NAME) a ete cree !$(NC)"

$(OBJDIR)%.o: $(SRCDIR)%.c	
	@gcc $(CFLAGS) -I $(INCDIR) -I $(LIBDIR)/includes/ -c -o $@ $^
	@echo "\t$(LBLUE)$@$(NC) ... [$(LGREEN)OK$(NC)]"

lib: 
	@make -C libft/

mlx:
	@make -C $(MLXDIR)

norme:
	norminette $(SRCDIR)*.c $(INCDIR)*.h

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBDIR) clean > /dev/null

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@make -C $(MLXDIR) clean
	@echo "$(LBLUE)Grand menage$(NC)"

re: fclean all

prefix:
	@mkdir -p $(OBJDIR)
	@echo "$(LBLUE)Compilation de $(NAME)$(NC) ..."