#include "shell.h"
/**
 * handle_cd - to handle the cd builtins
 * @directory: the desired directory
 */
void handle_cd(char *directory)
{
	char *new_dir;
	char current_dir[1024];

	if (directory == NULL || strcmp(directory, "~") == 0)
	{
		new_dir = getenv("HOME");
	}
	else if (strcmp(directory, "-") == 0)
	{
		new_dir = getenv("OLDPWD");
	}
	else
	{
		new_dir = directory;
	}
	if (new_dir == NULL)
	{
		fprintf(stderr, "cd: HOME not set\n");
		return;
	}
	if (chdir(new_dir) != 0)
	{
		perror("cd");
		return;
	}
	if (getcwd(current_dir, sizeof(current_dir)) != NULL)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_dir, 1);
	}
	else
	{
		perror("getcwd");
	}
}
