#include "minitalk.h"

#include <stdio.h>

//server

/* typedef struct s_action
{
	void	*handler;
}				t_action;

void handler(int signal)
{

} */

int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);		//change

	ft_printf("%d", len);
	//sigaction
	//sigaction(SIGUSR1, );
	while (1)
		pause();
}