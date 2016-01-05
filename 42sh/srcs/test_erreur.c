#include "../includes/sh.h"

int	test_erreur(int ac)
{
	if (ac != 1)
	{
		ft_putstr("Trop d'arguments");
		return (-1);
	}
	return (0);

}

void	test_erreur_env(char ***penv)
{
	char *path;

	path = "PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
	if (!*penv)
	{
		ad_elem_to_tab(*penv, path);
	}
}