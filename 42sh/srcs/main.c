#include "../includes/sh.h"

int main(int ac, char **av, char **env)
{
	(void)av;
	if(test_erreur(ac) == -1)
		return (0);
	test_erreur_env(&env);
	loop(&env);
	return (0);
}
