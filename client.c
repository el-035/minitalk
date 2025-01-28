#include "minitalk.h"

#include <stdio.h>

volatile int sig_g = 0;


char *convert_message(int msg, char *bits)
{
	int i;

	if (!bits)
	{
		bits = (char *)ft_calloc(9, sizeof(char)); // change to calloc
		if (!bits)
			return (NULL);
		//bits[8] = '\0';
	}
	else
		ft_bzero(bits, 9);
	i = 7;
	while (i >= 0)
	{
		bits[i] = (msg % 2) + '0';
		msg = msg / 2;
		i--;
	}
	return (bits);
}
void send_message(unsigned char *msg, int pid)
{
	int i;
	int j;
	char *bits;

	i = 0;
	bits = NULL;
	while (msg[i])
	{
		bits = convert_message(msg[i], bits);
		j = 0;
		while (j < 8)
		{
			if (bits[j] == '0')
				kill(pid, SIGUSR1);
			else if (bits[j] == '1')
				kill(pid, SIGUSR2);
			while(!sig_g)
				;
			sig_g = 0;
			j++;
		}
		i++;
	}
	lets_free(bits);
}

void send_terminator(int pid)
{
	int j;

	j = 0;
	while (j < 8) // send null terminator
	{
		kill(pid, SIGUSR1);
		j++;
		while(!sig_g)
			;
		sig_g = 0;
	}
}

void	lets_free(char *str)
{
	if(str)
	{
		free(str);
		str = NULL;
	}
}

// client

void handler(int sig)
{
	if (sig == SIGUSR1)
		sig_g = 1;
}

//send more then 1000
int main(int argc, char **argv)
{
	struct sigaction sig;
	int pid;	//check that is positive

	if (argc != 3 || !*argv[2] || !argv[2])
		return (0);			// error handling

	pid = ft_atoi(argv[1]); // change to log long
	if (pid <= 0)
		return 1;			//error
	sig.sa_handler = handler;
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	send_message((unsigned char *)argv[2], pid);
	send_terminator(pid);
	/* while (1)
		pause(); */
}
