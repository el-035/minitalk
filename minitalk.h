#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <signal.h>

/* typedef struct sigaction
{
	void	*sa_handler;
}			t_signal; */

//client
char	*convert_message(int msg);
void	send_message(char *msg, int pid);

//server

//utils
int	power(int base, int power);
char	*get_char(char *bits);

#endif