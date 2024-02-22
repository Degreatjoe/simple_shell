#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - a super simple shell
 *
 * Return: 0 always
 */
int main(void)
{
	char *cmd = NULL;
	size_t i = 0;
	pid_t child;
	int status;

	while (1)
	{
		printf("cisfun$ ");
		if (getline(&cmd, &i, stdin) == -1)
		{
			perror("status");
			return (1);
		}
		cmd[strcspn(cmd, "\n")] = 0;
		if (strcmp(cmd, "exit") == 0)
		{
			free(cmd);
			break;
		}
		child = fork();
		if (child == -1)
		{
			perror("error: ");
			return (1);
		}
		else if (child == 0)
		{
			char *av[2];

			av[0] = cmd;
			av[1] = NULL;
			execve(cmd, av, NULL);
			perror("status");
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
