NAME = lemin

SRCS =

INCLUDES = ./includes
FLAGS = -Wall -Wextra -Werror
OBJS = 


all : $(NAME)

$(NAME) : libft/libft.a
	@clang -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	@clang -o $(NAME) $(FLAGS) $(OBJS) -L libft/ -lft
	echo "Compilation reussie"

libft/libft.a :
	make -C libft

noflag : libft/libft.a
	@clang -c $(SRCS) -I $(INCLUDES)
	@clang -o $(NAME) $(OBJS) -L libft/ -lft
	echo "Compilation reussie"

norme :
	norminette

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.phony : all re clean fclean norme noflag lib
