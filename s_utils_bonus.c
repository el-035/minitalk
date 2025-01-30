/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 21:18:34 by efittant          #+#    #+#             */
/*   Updated: 2025/01/29 21:18:36 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	power(int base, int power)
{
	int	res;

	res = 1;
	while (power >= 1)
	{
		res *= base;
		power--;
	}
	return (res);
}

unsigned char	*get_char(char *bits)
{
	unsigned char	*letter;
	int				res;
	int				i;
	int				j;

	letter = (unsigned char *)ft_calloc(2, sizeof(char));
	if (!letter)
		return (NULL);
	res = 0;
	i = 7;
	j = 0;
	while (i >= 0)
	{
		if (bits[i] == '1')
			res = res + power(2, j);
		i--;
		j++;
	}
	letter[0] = res;
	return (letter);
}
