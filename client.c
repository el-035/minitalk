#include "minitalk.h"

#include <stdio.h>

volatile int sig_g = 0;

char *convert_message(int msg, char bits[9])
{
	int i;

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
	char bits[9];

	i = 0;
	ft_bzero(bits, 9);
	while (msg[i])
	{
		convert_message(msg[i], bits);
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
		usleep(200);
	}
}

int	return_pid(int pid)
{
	static int	temp_pid = 0;

	if (temp_pid != pid && pid != 0)
		temp_pid = pid;
	return (temp_pid);
}


void handler(int sig)
{
	if (sig == SIGUSR1)
		sig_g = 1;
	else if (sig == SIGINT)
	{
		send_terminator(return_pid(0));
		send_terminator(return_pid(0));
	}
	else if (sig == SIGUSR2)
		exit(1);
}
//check interruption
//funcheck
//valgrind

int main(int argc, char **argv)
{
	struct sigaction sig;
	int pid;

	if (argc != 3)
		errors("Invalid arguments\n", NULL);
	if (!*argv[2] || !argv[2])
		errors("Include a message to send\n", NULL);	
	pid = atoi_mt(argv[1]);
	return_pid(pid);
	if (kill(pid, 0) == -1)
		errors("No process with this pid\n", NULL);
	sig.sa_handler = handler;
	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGINT, &sig, NULL);
	send_message((unsigned char *)argv[2], pid);
	send_terminator(pid);
}
