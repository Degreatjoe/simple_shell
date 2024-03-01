#include "shell.h"
/**
 * execute - to execute the command
 * @token: the tokenized input
 * @argv: argument vector
 * @envp: environ
 *
 * Return: the status of the child process
 */
int execute(char **token, char **argv, char **envp)
{
	pid_t child;
	int status;
	char *executable;

	if (token[0] == NULL)
	{
		free_token(token);
		return (0);
	}
	executable = find_executable(token[0]);
	if (executable != NULL)
	{
		child = fork();
		if (child == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (child == 0)
		{
			if (execve(executable, token, envp) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				return (WEXITSTATUS(status));
		}
		free(executable);
	}
	else
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], token[0]);
	}
	free_token(token);
	return (WEXITSTATUS(status));
}
