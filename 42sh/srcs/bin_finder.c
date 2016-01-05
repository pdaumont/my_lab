#include "../includes/sh.h"

char 	*get_path(char ***penv)
{
	int j;
	char *str;

	j = -1;
	str = NULL;
	while ((*penv)[++j])
	{
		if (ft_strncmp((*penv)[j], "PATH", 4) == 0)
				str = ft_strsub((*penv)[j], 5, ft_strlen((*penv)[j]));
	}
	return (str);
}

char	*bin_finder(char **tab, char ***penv)
{
	char *path;
	char **paths;
	int i;
	int open;

	i = -1;
	open = -1;
	if ((path = get_path(penv)) == NULL)
	{
		ft_putstr("path failed\n");
		return (NULL);
	}
	paths = ft_strsplit(path, ':');
	while (open != 1 && paths[++i])
	{
		if (opendir(paths[i]))
		{
			paths[i] = ft_strjoin(paths[i], "/");
			paths[i] = ft_strjoin(paths[i], tab[0]);
			if (access(paths[i], R_OK | X_OK) != -1)
				open = 1;
		}
	}
	if (access(tab[0], R_OK | X_OK) != -1)
	{
		open = 1;
		paths[i] = ft_strdup(tab[0]);
	}
	if (open == -1)
	{
		ft_putstr(tab[0]);
		ft_putstr(" : Commande not found\n");
		return (NULL);
	}
//	fork() > 0 ? wait(0) : execve(paths[i], tab, *penv);
//	free_tab(paths);
//	free_tab(tab);
	return (paths[i]);
}
