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
	/**
	char *input;
	char **token;
	pid_t child;
	int status;
	char *path;

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
			path = find_path(token[0]);
			if (path)
			{
				child = fork();
				if (child == -1)
				{
					perror("fork");
					exit(EXIT_FAILURE);
				}
				else if (child == 0)
				{
					if (execve(path, token, NULL) == -1)
					{
						perror(argv[0]);
						exit(EXIT_FAILURE);
					}
				}
				else
				{
					wait(&status);
				}
				free(path);
			}
			else
			{
				perror("path");
			}
			free(token);
		}
		free(input);
	}
	return (0);
}
*/
    char *input;
    char **token;
    pid_t child;
    int status;
	char *executable;

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
            executable = find_executable(token[0]);
            if (executable != NULL)
            {
                child = fork();
                if (child == -1)
                {
                    perror("fork");
                    exit(EXIT_FAILURE);
                }
                else if (child == 0)
                {
                    if (execve(executable, token, NULL) == -1)
                    {
                        perror(argv[0]);
                        exit(EXIT_FAILURE);
                    }
                }
                else
                {
                    wait(&status);
                }
                free(executable);
            }
            else
            {
                printf("%s: command not found\n", token[0]);
            }
            free(token);
        }
        free(input);
    }
    return 0;
}
