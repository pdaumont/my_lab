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
//	printf("path finded = %s\n", paths[i]);
	return (paths[i]);
}


int	middle_pipe(char **cmd1, char **cmd2, char **env)
{
	int	pfd[2];
	int	pid;

	if (pipe(pfd) == -1)
	{
		ft_putstr("pipe failed\n");
		return -1;
	}
	if ((pid = fork()) < 0)
	{
		ft_putstr("fork failed\n");
		close(pfd[0]);
		close(pfd[1]);
		return -1;
	}
	if (pid == 0)
	{
		dup2(pfd[1], 1);
		close(pfd[0]);
		execve(bin_finder(cmd1, &env), cmd1, env) == -1 ? ft_putstr("cmd1 failed\n") : NULL;
		perror("error");
		return 0;
	}
	else
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
		wait(NULL);
		execve(bin_finder(cmd2, &env), cmd2, env) == -1 ? ft_putstr("cmd2 failed\n") : NULL;
		perror("error");
		return 0;
	}
}

int	main(int argc, char **argv, char **env)
{
	int	pfd[2];
	int	pid;
	char *cmd1[3];
	char *cmd2[3];
	char *cmd3[3];


	int fd[3] = {0, 1 , 2};

	cmd1[0] = "ls";
	cmd1[1] = "-lF";
	cmd1[2] = NULL;

	cmd2[0] = "cat";
	cmd2[1] = "-e";
	cmd2[2] = NULL;

	cmd3[0] = "wc";
	cmd3[1] = "-w";
	cmd3[2] = NULL;

	if (pipe(pfd) == -1)
	{
		ft_putstr("pipe failed\n");
		return -1;
	}
	if ((pid = fork()) < 0)
	{

		ft_putstr("fork failed\n");
		close(pfd[0]);
		close(pfd[1]);
		perror("error");
		return -1;
	}
	if (pid == 0)
	{
		close(pfd[0]);
		fd[1] = pfd[1];
		dup2(pfd[1], 1);
		middle_pipe(cmd1, cmd2, env);
		//execve(bin_finder(cmd2, &env), cmd2, env) == -1 ? ft_putstr("cmd1 failed\n") : NULL;
		perror("error 42");
		return(0);
	}
	else
	{
		dup2(pfd[0], 0);
		close(pfd[1]);
		wait(NULL);
		execve(bin_finder(cmd3, &env), cmd3, env) == -1 ? ft_putstr("cmd3 failed\n") : NULL;
		perror("error");
		return (0);
	}
	
	return (0);
}