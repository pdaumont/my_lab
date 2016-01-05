#include "../includes/sh.h"

char *tab_to_space(char *str)
{
	int i;
	char *temp;

	i = 0;
	if (!str)
		return NULL;
	temp = (char*)malloc(ft_strlen(str) * sizeof (char) + 1);
	while (str[i])
	{
		if (str[i] == '\t')
			temp[i] = ' ';
		else
			temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	ft_strdel(&str);
	return (temp);
}