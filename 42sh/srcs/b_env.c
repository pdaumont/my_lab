#include "../includes/sh.h"

void	b_env(char **env)
{
	int i;

	i = -1;
	while (env[++i])
	{
		ft_putstr(env[i]);
		ft_putstr("\n");
	}
}