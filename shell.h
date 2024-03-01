#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
void free_token(char **);
char *getInput();
char **tokenize(char *);
char *find_executable(char *command);
int execute(char **, char **, char **);
char *check_command(char *);
char *search_path(char *command, char *path_copy);
#endif
