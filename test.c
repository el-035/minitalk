/*Write a program to send a signal to itself using kill().
Add a signal handler to print a message when a signal is received.
*/
#include<signal.h>
#include<unistd.h>
#include <stdio.h>

int sigusr1_count = 0;
int sigusr2_count = 0;

void handle_signal(int signal)
{
  if (signal == SIGUSR1)
  {
    sigusr1_count++;
    printf("1: %d\n", sigusr1_count);
  }
  if (signal == SIGUSR2)
  {
    sigusr2_count--;
    printf("2: %d\n", sigusr2_count);
  }
}

int main (void)
{
  int pid = getpid();
  
  printf("%d\n", pid);
  signal(SIGUSR1, handle_signal);
  signal(SIGUSR2, handle_signal);
  
  /*kill(pid, SIGUSR1);*/
  
/*
  signal(SIGUSR2, handle_signal);
  kill(pid, SIGUSR2);*/
  while (1)
    pause();
}

