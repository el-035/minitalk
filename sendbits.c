#include<signal.h>
#include<unistd.h>
#include <stdio.h>
#include "minitalk.h"

char	*convert_message(char msg)
{
	char *bits;
	int	i;
	bits = (char *) ft_calloc (9, sizeof(char));	//change to calloc
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


int main (void)
{
	char *message;
	//int pid = getpid();

	message = "Hello\n";
	//printf("%d\n", pid);
	printf("%s", convert_message(message[0]));
	/* signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal); */
	
}

//strlen per vedere quanto è lungo il messaggio
//loop
	//converti msg[i] to binary
	//if 0 send sigusr1
	//else 2