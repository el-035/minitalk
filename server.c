#include "minitalk.h"

#include<stdio.h>

//server
void	print_signal(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("%s", message);
}

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);		//change
	signal(SIGUSR1, print_signal);
	while (1)
		pause();
}