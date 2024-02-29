#include "shell.h"
/**
 * main - Entry point for the shell program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, otherwise exit with failure
 */
int main(int argc, char **argv)
{
	char *input;
	char **token;

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
			execute(token, argv);
			free(input);
		}
		else
		{
			free(input);
			continue;
		}
	}
	return (0);
}
