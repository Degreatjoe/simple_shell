#include "shell.h"
/**
 * tokenize - to seperate the inputed string
 * getInput.
 *
 * Return: the tokenated strings
 */
#define MAX_INPUT 1024
char **tokenize(char *input)
{
	char **token = malloc(sizeof(char *) * MAX_INPUT);
	int i = 0;
	char *tok;

	if (!token)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	tok = strtok(input, " ");
	while (tok != NULL && i < MAX_INPUT)
	{
		token[i] = tok;
		i++;
		tok = strtok(NULL, " ");
	}
	token[i] = NULL;

	return (token);
}
