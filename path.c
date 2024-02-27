#include "shell.h"

char *find_path(char *input)
{
	struct stat st;
	char *path = getenv("PATH");
	char *path_copy = strdup(path);
	char *path_tok;
	char *f_path;

	if (!path_copy)
	{
		perror("strdup");
		return (NULL);
	}

	if (strchr(input, '/'))
	{
		if (stat(input, &st) == 0 && (st.st_mode & S_IXUSR))
		{
			free(path_copy);
			return (strdup(input));
		}
	}
	else
	{
		path_tok = strtok(path_copy, ":");
		while (path_tok)
		{
			f_path = malloc(strlen(path_tok) + strlen(input) + 2);
			if (!f_path)
			{
				perror("malloc");
				free(path_copy);
				return (NULL);
			}
			sprintf(f_path, "%s/%s", path_tok, input);
			if (stat(f_path, &st) == 0 && (st.st_mode & S_IXUSR))
			{
				free(path_copy);
				return (f_path);
			}
			free(f_path);
			path_tok = strtok(NULL, ":");
		}
	}
	free(path_copy);
	return (NULL);
}
