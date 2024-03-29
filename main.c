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

	while (argc == 1)
	{
		input = getInput();
		if (input != NULL)
		{
			token = tokenize(input);
			if (builtins(token, envp) != 0)
			{
				execute(token, argv, envp);
			}
			free(input);
			/*free_token(token);*/
		}
		else
		{
			free(input);
			continue;
		}
	}
	return (0);
}
