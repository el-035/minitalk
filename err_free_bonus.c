/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:41:37 by efittant          #+#    #+#             */
/*   Updated: 2025/01/29 21:29:37 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	errors(char *msg, char *free)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen((unsigned char *)msg));
	lets_free(free);
	exit(1);
}

void	lets_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}
