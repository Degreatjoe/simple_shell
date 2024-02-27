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
    char *path_copy, *dir, *abs_path;
    struct stat st;

    if (path == NULL || command == NULL)
        return NULL;

    path_copy = strdup(path);
    if (path_copy == NULL)
    {
        perror("strdup");
        exit(EXIT_FAILURE);
    }

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
        if (stat(abs_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
        {
            free(path_copy);
            return abs_path;
        }
        free(abs_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
