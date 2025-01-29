/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:29:48 by efittant          #+#    #+#             */
/*   Updated: 2025/01/29 21:29:50 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	is_digit(char *str, int pos)
{
	while (str[pos])
	{
		if (str[pos] < '0' || str[pos] > '9')
			errors("pid invalid\n", NULL);
		pos++;
	}
}

int	atoi_mt(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		errors("Invalid pid\n", NULL);
	is_digit((char *)str, i);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
		result = result * 10 + str[i++] - 48;
	if (result > 2147483647 || result == 0)
		errors("Invalid pid\n", NULL);
	return ((int)result);
}

int	return_pid(int pid)
{
	static int	temp_pid = 0;

	if (temp_pid != pid && pid != 0)
		temp_pid = pid;
	return (temp_pid);
}

int	return_flag(int flag)
{
	static int	t_flag = 0;

	if (flag != 1)
		t_flag = flag;
	return (t_flag);
}
