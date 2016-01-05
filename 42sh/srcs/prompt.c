#include "../includes/sh.h"

int		user(char **env, char **pname)
	{
		int		i;
		char	*str;

		i = 0;

		while (env[i])
		{
			if (ft_memcmp("USER=", env[i], 5) == 0)
			{
				str = ft_strsub(env[i], 5, ft_strlen(env[i]));
				*pname = str;
				return (0);
			}
			i++;
		}
		str = "unknown";
		*pname = str;
		return (0);
	}

void	prompt(char **cmd, char **env)
{
	char *name;

	if (display_prompt(0) == 0)
	{
		if (user(env, &name) == 0)
			ft_putstr(name);
		ft_putstr("$>");
		display_prompt(1);
		get_next_line(0, cmd);
	}
}