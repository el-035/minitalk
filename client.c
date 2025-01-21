#include "minitalk.h"

#include<stdio.h>

char	*convert_message(char msg)
{
	char *bits;
	int	i;

	bits = (char *) malloc (9 * sizeof(char));	//change to calloc
	if (!bits)
		return (NULL);
	bits[8] = '\0';
	i = 7;
	while (i >= 0)
	{
		bits[i] = (msg % 2) + '0';
		msg = msg / 2;
		i--;
	}
	return (bits);
}

//client
int main (int argc, char **argv)
{
	int 	pid;
	int		i;
	int		j;
	char	*bits;

	if (argc != 3)
		return (0);		//error handling
	i = 0;
	j = 0;
	pid = ft_atoi(argv[1]);	//change to ft
	while (argv[i])
	{
		bits = convert_message(*argv[i]);
		while(j <= 7)
		{
			if (bits[j] == '0')
				kill(pid, SIGUSR1);
			else if (bits[j] == '1')
				kill(pid, SIGUSR2);
			j++;
		}
		i++;
	}
}