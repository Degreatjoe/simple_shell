#include "shell.h"
/**
 * find_executable - search for executable in the directories specified in PATH
 * @command: name of the command to search for
 *
 * Return: absolute path of the executable if found, NULL otherwise
 */
char *find_executable(char *command)
{
	char *path = getenv("PATH");
	char *path_copy, *executable;

	executable = check_command(command);
	if (executable != NULL)
	{
		return (executable);
	}
	if (path == NULL || command == NULL)
	{
		return (NULL);
	}
	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	return (search_path(command, path_copy));
}
