#include "minitalk.h"

#include<stdio.h>


//client
int main (int argc, char **argv)
{
	int pid;

	if (argc != 3)
		return (0);		//error handling
	message = argv[2];
	pid = ft_atoi(argv[1]);	//change to ft
	kill(pid, SIGUSR1);
}