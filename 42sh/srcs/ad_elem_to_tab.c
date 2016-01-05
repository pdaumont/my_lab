#include "../includes/sh.h"

char **ad_elem_to_tab(char **tab, char *elem)
{
	char *str;
	char **tmp;
	int i;

	i = 0;
	if (!tab || tab[0] == '\0')
		return NULL;
	else if (!elem)
		return (tab);
	else
	{
		str = tab[0];
		while (tab[++i])
		{
			str = ft_strjoin(str, " ");
			str = ft_strjoin(str, tab[i]);
		}
		str = ft_strjoin(str, " ");
		str = ft_strjoin(str, elem);
		tmp = ft_strsplit(str, ' ');
		//free_tab(&tab);
		return (tmp);
	}
}