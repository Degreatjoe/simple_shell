#include "shellib.h"

/**
 * main - recieves the command line argument
 * @argv: argument vector
 * @argc: argument count
 * @envp: environment variables
 * Return: (0) on success
 */
int main(int argc, char **argv, char **envp)
{
	if (argc == 1)
		get_p(argv, envp);
	return (0);
}
