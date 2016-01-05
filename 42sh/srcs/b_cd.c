#include "../includes/sh.h"

void	home(char ***penv)
{
	int j;
	char **tab;
	char *str;

	j = -1;

	while ((*penv)[++j])
	{
		if (ft_strncmp((*penv)[j], "HOME", 4) == 0)
		{
			str = ft_strsub((*penv)[j], 6, ft_strlen((*penv)[j]));
			tab = ft_strsplit(ft_strjoin("cd /", str), ' ');
			b_cd(0, tab, penv);
			break;
		}
	}
}

void	back(char ***penv)
{
	int j;
	char *str;
	char **tab;

	j = -1;
	while ((*penv)[++j])
	{
		if (ft_strncmp((*penv)[j], "OLDPWD", 6) == 0)
			{
				str = ft_strsub((*penv)[j], 8, ft_strlen((*penv)[j]));
				tab = ft_strsplit(ft_strjoin("cd /", str), ' ');
				b_cd(0, tab, penv);
				break;
			}
	}
}

void	go_to(int i, char **tab, char ***penv)
{
	char pwd[1024];
	char **cmd;

	getcwd(pwd, sizeof(pwd));
	cmd = ft_strsplit(ft_strjoin("setenv OLDPWD ", pwd), ' ');
	b_setenv(0, cmd, penv);
	chdir(tab[i + 1]);
	getcwd(pwd, sizeof(pwd));
	cmd = ft_strsplit(ft_strjoin("setenv PWD ", pwd), ' ');
	b_setenv(0, cmd, penv);
}




void	b_cd(int i, char **tab, char ***penv)
{
	struct stat sb;

	printf("in cd\n");
	if (!tab [i + 1] || (ft_strcmp(tab[i + 1], "~") == 0))
		home(penv);
	else if ((ft_strcmp(tab[i + 1], "-") == 0))
		back(penv);
	else
		{ 
			if (stat(tab[i + 1], &sb) == -1) 
	    		return (ft_putstr("PB stat.\n"));
			if((sb.st_mode & S_IFMT) == S_IFDIR)
			{
				if (S_IXUSR & sb.st_mode)
					go_to(i, tab, penv);
				else
				{
				ft_putstr(tab[i + 1]);
				ft_putstr(": Permission denied.\n");
				}
			}
			else
			{ 
				ft_putstr(tab[i + 1]);
				ft_putstr(": No such file or directory.\n");
			}
		}
}