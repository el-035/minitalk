#include<signal.h>
#include<unistd.h>
#include <stdio.h>

int	convert_message(char **message)
{
	
}


int main (void)
{
	char *message;
	int pid = getpid();

	printf("%d\n", pid);
	/* signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal); */
	
}

//strlen per vedere quanto è lungo il messaggio
//loop
	//converti msg[i] to binary
	//if 0 send sigusr1
	//else 2