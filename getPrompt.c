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
		child = fork();
		if (child == -1)
			perror("error");
		else if (child == 0)
		{
			if (execve(input, argv, envp) == -1)
			{
				perror(argv[0]);
				exit(1);
			}
		}
		wait(&status);
	}
	/*free(input);*/
	input = NULL;
	i = 0;
	return (0);
}
