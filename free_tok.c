#include "shell.h"
/**
 * free_token - frees memory allocated for token
 * @tokens: the tokens to be freed
 */
void free_token(char **tokens)
{
	int i = 0;

	while (tokens[i] != NULL)
	{
		free(tokens[i]);/* Free each duplicate string*/
		i++;
	}
	free(tokens);/* Free the array of pointers*/
}

