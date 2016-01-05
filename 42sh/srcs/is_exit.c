#include "../includes/sh.h"

int is_exit(char *str)
{
	int len;
	char *temp;

	if (ft_strnequ("exit", str, 4) == 1)
	{
		len = ft_strlen(str);
		temp = ft_strsub(str, 4, len - 4 + 1);
		len = ft_atoi(temp);
		return (len);
	}
	return (-1);
}