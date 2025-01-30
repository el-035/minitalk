/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:41:49 by efittant          #+#    #+#             */
/*   Updated: 2025/01/29 20:41:50 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "ft_printf/ft_printf.h"
# include <signal.h>
# include <stdlib.h>

// client
char			*convert_message(int msg, char bits[9]);
void			send_message(unsigned char *msg, int pid);
void			send_terminator(int pid);
void			handler(int sig);

// server
unsigned char	*save_msg(char *char_bits, unsigned char *msg);
int				is_terminator(char *bits);
void			print_msg(unsigned char **msg, int pid);
void			s_handler(int signal, siginfo_t *info, void *ucontext);

// free err
void			errors(char *msg, char *free);
void			lets_free(char *str);

// client utils
void			is_digit(char *str, int pos);
int				atoi_mt(const char *str);
int				return_pid(int pid);
int				return_flag(int flag);

// ft_libft
void			ft_putstr_fd(unsigned char *s, int fd);
void			*ft_calloc(size_t nmemb, size_t size);
size_t			ft_strlen(const unsigned char *str);
unsigned char	*ft_strjoin(const unsigned char *s1, const unsigned char *s2);
void			ft_bzero(void *s, size_t n);

// server utils
int				power(int base, int power);
unsigned char	*get_char(char *bits);

#endif
