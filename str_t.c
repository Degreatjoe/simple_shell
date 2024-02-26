#include "shellib.h"
/**
 * str_t - functuion that seperates the input
 * @cmd: the string to be seperated
 *
 * Return: the seperated sting.
 */

char **str_t(char *cmd)
{
	char **stat;
	int i = 0;

	stat = malloc(sizeof(char **));
	if (!stat)
	{
		perror("allocation error");
	}

	stat[i] = strtok(cmd, " ");
	while (stat[i] != NULL)
	{
		i++;
		stat[i] = strtok(NULL, " ");
	}
	return (stat);
}
