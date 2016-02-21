NAME = lem-in

SRCS = ./src/lemin_acquisition.c ./src/lemin_main.c ./src/get_next_line.c ./src/lemin_traitement.c\
./src/lemin_matrice.c ./src/lemin_print.c

INCLUDES = ./includes
FLAGS = -Wall -Wextra -Werror
OBJS = ./lemin_acquisition.o ./lemin_main.o ./get_next_line.o ./lemin_traitement.o ./lemin_matrice.o ./lemin_print.o


all : $(NAME)

$(NAME) : libft/libft.a
	@gcc -c $(FLAGS) $(SRCS) -I $(INCLUDES)
	@gcc -o $(NAME) $(FLAGS) $(OBJS) -L libft/ -lft
	echo "Compilation reussie"

/src/libft/libft.a :
	make -C /libft

noflag : libft/libft.a
	@gcc -c $(SRCS) -I $(INCLUDES)
	@gcc -o $(NAME) $(OBJS) -L libft/ -lft
	echo "Compilation reussie"

norme :
	norminette

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.phony : all re clean fclean norme noflag lib
