#include "shell.h"
/**
 * handle_pwd - to handle pwd builtin command
 */
void handle_pwd(void)
{
	char cwd[1024];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("%s\n", cwd);
	}
	else
	{
		perror("getcwd");
	}
}
/**
 * handle_echo - to handle echo builtiin command
 * @args: the arguments to be echoed
 */
void handle_echo(char **args)
{
	int i = 1;

	while (args[i] != NULL)
	{
		printf("%s ", args[i]);
		i++;
	}
	printf("\n");
}
/**
 * handle_exit - to handle exit builtin command
 */
void handle_exit(void)
{
	exit(0);
}
