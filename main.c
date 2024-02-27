#include "shell.h"
/**
 * main - a simple shell program
 * @argc: argument count
 * @argv: argument vectori
 *
 * Return: (0) on success
 */
int main(int argc, char **argv)
{
	char *input;
	char **token;
	pid_t child;
	int status;

	while (argc == 1)
	{
		input = getInput();
		if (input != NULL)
		{
			if (strcmp(input, "exit") == 0)
			{
				free(input);
				break;
			}
			token = tokenize(input);
			child = fork();
			if (child == -1)
			{
				perror("fork");
				exit(EXIT_FAILURE);
			}
			else if (child == 0)
			{
				if (execve(token[0], token, NULL) == -1)
				{
					perror(argv[0]);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				wait(&status);
			}
			free(token);
		}
		free(input);
	}
	return (0);
}
