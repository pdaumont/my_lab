#include "../includes/sh.h"

void	b_unsetenv(int i, char **tab, char ***penv)
{
	int pos;

	if (tab[i + 1] == NULL)
		return ;
	if ((pos = is_new_elem(i, tab, penv)) != -1) 
	{ 
		printf("pos ? %s\n", (*penv)[pos]);

		while ((*penv)[pos + 1])
		{
		(*penv)[pos] = (*penv)[pos + 1];
		pos++;
		}
		(*penv)[pos] = (*penv)[pos + 1];
	}

}
