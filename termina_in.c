#include "shell.h"
/**
 * terminal_input - to recieve input directly from terminal
 *
 * Return: the input on success
 */
char *terminal_input(void)
{
	    char *input = NULL;
	    size_t i = 0;
	    ssize_t str_len;

		str_len = getline(&input, &i, stdin);
		if (feof(stdin))
		{
			free(input);
			/*printf("\n");*/
			exit(EXIT_SUCCESS);
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
