#include "../includes/sh.h"

void	loop(char ***penv)
{
	char	*read;
	node	*tree;

	read = NULL;
	while(42)
	{
		prompt(&read, (char **)*penv);
		lexing_parsing_main(&read, &tree);
		//cmds = split_cmds(&read);
		//direction(cmdsliste);
	}
}
