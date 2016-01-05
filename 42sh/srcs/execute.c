#include "../includes/sh.h"

void	execute(char **cmd, char ***penv)
{
	int i;
	int exit_code;

	i = -1;
	while (cmd[++i])
	{
		printf("%s\n", cmd[i]);
		if((exit_code = is_exit(cmd[i])) != -1)
		{
			//free_tab(cmd);
			exit(exit_code);
		}
		else if (built_in_pipe(i, cmd, penv) != -1)
			return ;
		//else if (bin_finder(cmd, penv) != -1)
			return ;
	}
}
