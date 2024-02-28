#include "shell.h"
/**
 * search_path - to search for command in the directories
 * @command: the command to search for
 * @path_copy: a copy of the path environment variable
 *
 * Return: absolute path of the executable if found, NULL otherwise
 */
char *search_path(char *command, char *path_copy)
{
	char *dir, *abs_path;
	struct stat st;

	dir = strtok(path_copy, ":");
	while (dir != NULL)
	{
		abs_path = malloc(strlen(dir) + strlen(command) + 2);
		if (abs_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		sprintf(abs_path, "%s/%s", dir, command);
		if (stat(abs_path, &st) == 0 && S_ISREG(st.st_mode) &&
				(st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (abs_path);
		}
		free(abs_path);
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
