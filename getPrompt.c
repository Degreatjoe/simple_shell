#include "shellib.h"
/**
 * get_p - the basic shell function.
 * @argv: argument vector
 * @envp: enviroment variable
 * Return: (0) on success
 */
int get_p(char **argv, char **envp)
{
	ssize_t k;
	size_t i = 0;
	char *input = NULL;
	pid_t child;
	int status;
	char **args;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		k = getline(&input, &i, stdin);
		if (feof(stdin))
		{
			free(input);
			printf("\n");
			break;
		}
		if (k > 0 && input[k - 1] == '\n')
			input[k - 1] = '\0';
		if (k == -1)
			perror("error");
		args = str_t(input);
		child = fork();
		if (child == -1)
			perror("error");
		else if (child == 0)
		{
			if (execve(args[0], args, envp) == -1)
			{
				perror(argv[0]);
				exit(1);
			}
		}
		wait(&status);
		free(args);
	}
	input = NULL;
	i = 0;
	return (0);
}
