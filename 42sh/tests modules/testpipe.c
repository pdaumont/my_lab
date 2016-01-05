#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

void	ft_pipe()
{
	int fildes[2];
	pid_t	child;
	char *cmd1 = NULL;
	char *cmd2 = NULL;
	char *args1[3];
	char *args2[3];
	int const READ_END = 0;
	int	const WRITE_END = 1;

	cmd1 = "/usr/local/bin/echo";
	args1[0] = cmd1;
	args1[1] = " caca";
	args1[2] = NULL;

	cmd2 = "user/local/bin/cat";
	args2[0] = cmd2;
	args2[1] = " -e";
	args2[2] = NULL;

	pipe(fildes);
	child = fork();
	if (child == 0)
	{
		printf("in child 2\n");
		dup2(fildes[READ_END], STDOUT_FILENO);
		printf("%d\n",STDOUT_FILENO);
		close(fildes[WRITE_END]);
		execve(cmd1, args1, NULL);
		perror("error");
		return;
	}
	dup2(fildes[READ_END], STDIN_FILENO);
	close(fildes[WRITE_END]);
	wait(NULL);
	printf("in child 3\n");
	execve(cmd2, args2, NULL);
	perror("error");
	return;
}

int main()
{
	pid_t child;

	child = fork();
	if (child == 0)
	{
		printf("in child 1\n");
		ft_pipe();
		//perror("error");
		return (0); 
	}
	wait(NULL);
	printf("in daddy\n");
	return(0);
} 
