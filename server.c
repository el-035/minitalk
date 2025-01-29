#include "minitalk.h"
#include <stdio.h>	//delete


unsigned char *save_msg(char *char_bits, unsigned char *msg)
{
	unsigned char	*letter;
	unsigned char	*temp;

	letter = get_char(char_bits); //protect
	if (!letter)
		errors("Allocation failed\n", (char *)msg);
	if (!msg)
		return (letter);
	temp = msg;
	msg = ft_strjoin(msg, letter);
	if (!msg)
		errors("Allocation failed\n", (char *)msg);	//handle error
	return (free(temp), temp = NULL, free(letter), letter = NULL, msg);
}

int	is_terminator(char *bits)
{
	int	i;

	i = 0;
	while(bits[i])
	{
		if (bits[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

void	print_msg(unsigned char **msg, int pid)
{
	kill(pid, SIGUSR2);
	write(1, (const char *)(*msg), ft_strlen(*msg));
	write(1, "\n", 1);
	free(*msg);
	*msg = NULL;
}

void handler(int signal, siginfo_t *info, void *ucontext)
{
	static int				i = 0;
	static char				char_bits[9] = {0};
	static unsigned char	*msg = NULL;

	(void) ucontext;
	if (signal == SIGUSR1)	//0
	{
		char_bits[i++] = '0';
		if(i != 8 || is_terminator(char_bits) != 1)
			kill(info->si_pid, SIGUSR1);
	}
	else if (signal == SIGUSR2)	//1
	{
		char_bits[i++] = '1';
		kill(info->si_pid, SIGUSR1);
	}
	if (i == 8)
	{
		if (is_terminator(char_bits) == 1)
			print_msg(&msg, info->si_pid);
		else
			msg = save_msg(char_bits, msg); //error handling
		ft_bzero(char_bits, 9);
		i = 0;
	}
}

int main(void)
{
	struct sigaction sig;
	int		pid;

	pid = getpid();
	ft_printf("%d\n", pid);		//change
	sig.sa_sigaction = handler;
 	sig.sa_flags = SA_SIGINFO;
	sigemptyset(&sig.sa_mask);
 	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
