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
	int child_status;

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
			else
			{
				token = tokenize(input);
				child_status = execute(token, argv, envp);
				free(input);
				return (child_status);
			}
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
