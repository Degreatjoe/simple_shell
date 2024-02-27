#include "shell.h"
/**
 * getInput - to recieve input from user
 *
 * Return: the input on success
 */
char *getInput(void)
{
	char *input = NULL;
	size_t i = 0;
	ssize_t str_len;

	printf("$ ");
	str_len = getline(&input, &i, stdin);
	if (feof(stdin))
	{
		free(input);
		printf("\n");
		exit(1);
	}
	if (str_len == -1)
	{
		perror("Error ");
		exit(EXIT_FAILURE);
	}
	if (str_len > 0 && input[str_len - 1] == '\n')
		input[str_len - 1] = '\0';
	return (input);
}
