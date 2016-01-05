#include "../includes/sh.h"

void	lexing_parsing_main(char **read, node **tree)
{
	t_list	*cmds_liste;
	int		key;

	key = 54;
	cmds_liste = ft_lstnew(*read, sizeof(*read));
	ft_putlst(cmds_liste);
	addnode(tree, key, cmds_liste);
	printf("in\n");
	print_tree(*tree);
}