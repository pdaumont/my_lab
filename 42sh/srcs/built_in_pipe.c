#include "../includes/sh.h"

int	built_in_pipe(int i, char **tab, char ***penv)
{
	if( ft_strcmp(tab[i], "env") == 0)
	{
		b_env(*penv);
		return (0);
	}
	else if (ft_strnequ(tab[i], "setenv", 6) == 1)
	{
		b_setenv(i, tab, penv);
		return (0);
	}
	else if (ft_strnequ(tab[i], "unsetenv", 8) == 1)
	{
		b_unsetenv(i, tab, penv);
		return (0);
	}
	else if ((ft_strncmp(tab[i], "cd", 2)) == 0)
	{
		b_cd(i, tab, penv);
		return (0);
	}
	return (-1);
}