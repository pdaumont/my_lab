#include "./includes/sh.h"

int	main()
{
	unsigned int key;
	node *arbre;

	arbre = NULL;
	addnode(&arbre, 30, "la");
	addnode(&arbre, 11, " vie");
	addnode(&arbre, 30, " est");
	addnode(&arbre, 32, " belle");
	addnode(&arbre, 1, " et");
	addnode(&arbre, 4, " la");
	addnode(&arbre, 5, " mort");
	addnode(&arbre, 6, " est");
	addnode(&arbre, 1, " douce");

	ft_putstr("-------------------------------------\n");
	print_tree(arbre);
	ft_putstr("-------------------------------------\n");
	print_reverse_tree(arbre);
	ft_putstr("-------------------------------------\n");

	key = 1;
	if (search_node(arbre, key))
	{
		ft_putstr("la cle existe et vaut : ");
		ft_putnbr(key);
		ft_putstr("\n");
	}
	else
		ft_putstr("la cle n existe pas\n");
	key = 66;
		if (search_node(arbre, key))
	{
		ft_putstr("la cle existe et vaut : ");
		ft_putnbr(key);
		ft_putstr("\n");
	}
	else
		ft_putstr("la cle n existe pas\n");

	clear_tree(&arbre);
	return (0);
}