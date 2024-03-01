#include "shell.h"
/**
 * builtins - to execute builtin command
 * @token: command to execute
 * @envp: environment variable
 *
 * Return: 0 on succss otherwise -1
 */
int builtins(char **token, char **envp)
{
	if (token[0] != NULL)
	{
		if (strcmp(token[0], "cd") == 0)
		{
			handle_cd(token[1]);
		}
		else if (strcmp(token[0], "pwd") == 0)
		{
			handle_pwd();
		}
		else if (strcmp(token[0], "echo") == 0)
		{
			handle_echo(token);
		}
		else if (strcmp(token[0], "exit") == 0)
		{
			handle_exit();
		}
		else if (strcmp(token[0], "env") == 0)
		{
			handle_env(envp);
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}
