#include "../includes/sh.h"

int		is_new_elem(int i, char **tab, char ***penv)
{
	int j;

	j = -1;
	while ((*penv)[++j])
	{
		if (ft_strncmp((*penv)[j], tab[i + 1],ft_strlen(tab[i + 1])) == 0)
			return (j);
	}
	return(-1);
}

void	set_new_elem(int i, char **tab, char ***penv)
{
	char *str;

	if (!tab[i + 2])
		{
			str = ft_strjoin(tab[i + 1], "=");
			*penv = ad_elem_to_tab(*penv, str);
			return ;
		}
	else
		{
			str = ft_strjoin(tab[i + 1], "=");
			str = ft_strjoin(str, tab[i + 2]);
			*penv = ad_elem_to_tab(*penv, str);;
		}
}

void	replace_old_elem(int i, char **tab, char ***penv, int pos)
{
	char *str;

	str = ft_strjoin(tab[i + 1], "=");
	str = ft_strjoin(str, tab[i + 2]);
	(*penv)[pos] = str;
}

void	b_setenv(int i, char **tab, char ***penv)
{
	int	pos;

	if (!tab[i + 1])
	{
		b_env(*penv);
		return ;
	}
	else if (tab[i + 2] && tab[i + 3]!= '\0')
		{
			ft_putstr("setenv: Too many arguments.\n");
			return ;
		}
	else 
		((pos = is_new_elem(i, tab, penv)) == -1) ? set_new_elem(i, tab, penv) : replace_old_elem(i, tab, penv, pos);
}