/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efittant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 20:41:29 by efittant          #+#    #+#             */
/*   Updated: 2025/01/29 20:41:31 by efittant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putstr_fd(unsigned char *s, int fd)
{
	if (!s)
		return ;
	write(fd, (const char *)s, ft_strlen(s));
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;
	size_t	temp;

	temp = (nmemb * size);
	if (nmemb != 0 && temp / nmemb != size)
		return (NULL);
	mem = malloc(nmemb * size);
	if (mem == NULL)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}

size_t	ft_strlen(const unsigned char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned char	*ft_strjoin(const unsigned char *s1, const unsigned char *s2)
{
	size_t			mem;
	size_t			len1;
	size_t			len2;
	size_t			i;
	unsigned char	*join;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = len1 + len2 + 1;
	join = (unsigned char *)ft_calloc(mem, sizeof(char));
	if (join == NULL)
		return (NULL);
	while (len1-- > 0)
		join[i++] = *s1++;
	while (len2-- > 0)
		join[i++] = *s2++;
	return (join);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*res;

	res = s;
	while (n-- > 0)
		*res++ = '\0';
}
