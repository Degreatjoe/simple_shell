#include "shell.h"
/**
 * handle_env - to handle the env builtin call
 * @envp: the environment variable to print
 */
void handle_env(char **envp)
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
