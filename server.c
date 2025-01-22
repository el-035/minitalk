#include "minitalk.h"

#include <stdio.h>	//delete


char *save_msg(char *char_bits, char *msg)
{
	char	letter;

	letter = get_char(char_bits);
	msg = ft_strjoin(msg, &letter);
	if (!msg)
		return NULL;	//handle error
	return (msg);
}

void handler(int signal)
{
	static int	i = 0;
	static char	char_bits[9] = {0};
	static char	*msg = NULL;

	if (i == 8)
	{
		msg = save_msg(char_bits, msg);
		// if charbits é solo zeri allora é finita e possiamo stampare il messaggio
		ft_bzero(char_bits, 9);
		i = 0;
	}
	if (signal == SIGUSR1)	//0
		char_bits[i] = '0';
	else if (signal == SIGUSR2)	//1
		char_bits[i] = '1';
	i++;
}

int main(void)
{
	struct sigaction sig;
	int		pid;

	pid = getpid();
	ft_printf("%d\n", pid);		//change
	sig.sa_handler = handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);

	while (1)
		pause();
}
