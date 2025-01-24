#include "minitalk.h"
#include <stdio.h>	//delete


char *save_msg(char *char_bits, char *msg)
{
	char	*letter;
	char	*temp;
	char	*te;

	letter = get_char(char_bits); //protect
	if (!msg)
		return (letter);
	te = letter;
	temp = msg; //also free letter
	msg = ft_strjoin(msg, letter);
	if (!msg)
		return NULL;	//handle error
	return (free(temp), temp = NULL, free(te), te = NULL, msg);
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

void handler(int signal)
{
	static int	i = 0;
	static char	char_bits[9] = {0};
	static char	*msg = NULL;

	char_bits[8] = '\0';
	if (signal == SIGUSR1)	//0
		char_bits[i++] = '0';
	else if (signal == SIGUSR2)	//1
		char_bits[i++] = '1';
	if (i == 8)
	{
		if (is_terminator(char_bits) == 1)
		{
			ft_putstr_fd(msg, 1);
			free(msg);
			msg = NULL;
		}
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
	sig.sa_handler = handler;
 	sig.sa_flags = SA_RESTART;
	sigemptyset(&sig.sa_mask);
	sigaddset(&sig.sa_mask, SIGUSR1);
	sigaddset(&sig.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
}
