#include "minitalk.h"

#include<stdio.h>

//server



int main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d\n", pid);		//change

	while (1)
		pause();
}