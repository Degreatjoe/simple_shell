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
void execute(char **, char **, char **);
char *check_command(char *);
char *search_path(char *command, char *path_copy);
void handle_env(char **envp);
void handle_cd(char *path);
void handle_pwd();
void handle_echo(char **args);
void handle_exit();
int builtins(char **token, char **envp);
#endif
