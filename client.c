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
			if(sig_g == 3)
				return(lets_free((char *) msg), exit(1));
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

void handler(int sig)
{
	if (sig == SIGUSR1)
		sig_g = 1;
	else if (sig == SIGINT)
		sig_g = 2;
	else if (sig == SIGUSR2)
		sig_g = 3;
}

//check interruption
//if send \n and so on it prints them
//if sending multiple message from different pids
		//the first client ends in an infinite loop
int main(int argc, char **argv)
{
	struct sigaction sig;
	int pid;

	if (argc != 3)
		errors("Invalid arguments\n", NULL);
	if (!*argv[2] || !argv[2])
		errors("Include a message to send\n", NULL);	
	pid = atoi_mt(argv[1]);
	if (kill(pid, 0) == -1)
		errors("No process with this pid\n", NULL);
	sig.sa_handler = handler;
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGINT, &sig, NULL);
	if(sig_g == 2)
	{
		send_terminator(pid);
		send_terminator(pid);
		sig_g = 0;
	}
	send_message((unsigned char *)argv[2], pid);
	send_terminator(pid);
}
