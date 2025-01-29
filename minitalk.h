#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <signal.h>

typedef struct s_bits
{
	char	*bits;
}				t_bits;



//client
char	*convert_message(int msg, char *bits);
void	send_message(unsigned char *msg, int pid);
void	lets_free(char *str);

//server

//ft_libft
void	ft_putstr_fd(unsigned char *s, int fd);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(const unsigned char *str);
unsigned char	*ft_strjoin(const unsigned char *s1, const unsigned char *s2);
void	ft_bzero(void *s, size_t n);
int	ft_atoi(const char *str);
int	atoi_mt(const char *str);
void errors(char *msg, char *free);
void	is_digit(char *str, int pos);

//utils
int		power(int base, int power);
unsigned char	*get_char(char *bits);

#endif