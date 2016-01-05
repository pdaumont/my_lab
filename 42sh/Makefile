NAME = ft_minishell1

SRCS = ./srcs/main.c ./srcs/loop.c ./srcs/test_erreur.c ./srcs/prompt.c  ./srcs/display_prompt.c ./srcs/get_next_line.c \
./srcs/tab_to_space.c ./srcs/execute.c ./srcs/is_exit.c ./srcs/free_tab.c ./srcs/built_in_pipe.c ./srcs/b_env.c\
./srcs/b_setenv.c ./srcs/ad_elem_to_tab.c ./srcs/b_unsetenv.c ./srcs/b_cd.c ./srcs/bin_finder.c \
./srcs/lexeur_parseur/lexing_parsing_main.c

INCLUDES = ./includes
FLAGS = -Wall -Wextra -Werror
OBJS = ./main.o ./loop.o ./test_erreur.o ./prompt.o ./display_prompt.o ./get_next_line.o ./tab_to_space.o ./execute.o ./is_exit.o ./free_tab.o ./built_in_pipe.o ./b_env.o\
./b_setenv.o ./ad_elem_to_tab.o ./b_unsetenv.o ./b_cd.o ./bin_finder.o lexing_parsing_main.o


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
