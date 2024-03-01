#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 * @envp: environment variable
 *
 * Return: 0 on success, otherwise exit with failure
 */
int main(int argc, char **argv, char **envp)
{
	char *input;
	char **token;
	int execve_return;

	if (!isatty(STDIN_FILENO))
	{
		input = terminal_input();
		if (input != NULL)
		{
			token = tokenize(input);
			execve_return = execute(token, argv, envp);
			free(input);
			free_token(token);
			exit(execve_return);
		}
	}
	else
	{
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
				execute(token, argv, envp);
				free(input);
				/*free_token(token);*/
			}
			else
			{
				free(input);
				continue;
			}
		}
	}
	return (0);
}
