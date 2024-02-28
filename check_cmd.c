#include "shell.h"
/**
 * check_command - check if command is executale
 * @command: the command to check
 *
 * Return: absolute path of the command if executable, NULL otherwise
 */
char *check_command(char *command)
{
	struct stat st;

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &st) == 0 && S_ISREG(st.st_mode) &&
				(st.st_mode & S_IXUSR))
		{
			return (strdup(command));
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
