#include "minitalk.h"

#include<stdio.h>

char	*convert_message(int msg)
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

void	send_message(char *msg, int pid)
{
	int		i;
	int		j;
	char	*bits;

	i = 0;
	j = 0;
	bits = NULL;
	while (msg[i])
	{
		if (bits)
			free(bits);
		bits = convert_message(msg[i]);
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
	j = 0;
	while (j >= 7)	//send null terminator
	{
		kill(pid, SIGUSR1);
		j--;
	}
	free(bits);
}


//client
int main (int argc, char **argv)
{
	int 	pid;

	if (argc != 3)
		return (0);		//error handling
	pid = ft_atoi(argv[1]);	//change to ft
	send_message(argv[2], pid);
	//free bits or just not allocate
}