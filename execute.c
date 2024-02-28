#include "shell.h"
/**
 * execute - to execute the command
 * @token: the tokenized input
 * @argv: argument vector
 */
void execute(char **token, char **argv)
{
	pid_t child;
	int status;
	char *executable;

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
			if (execve(executable, token, NULL) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
		free(executable);
	}
	else
	{
		printf("%s: No such file or directory\n", token[0]);
	}
	free(token);
}
