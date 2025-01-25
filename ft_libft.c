#include "minitalk.h"

void	ft_putstr_fd(unsigned char *s, int fd)
{
	if(!s)
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
	size_t	mem;
	size_t	len1;
	size_t	len2;
	size_t	i;
	unsigned char	*join;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	mem = len1 + len2 + 1;
	join = (unsigned char *) ft_calloc(mem, sizeof(char));
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

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	n;

	n = 1;
	i = 0;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n = -1;
		i++;
	}
	if (str[i])
	{
		while (str[i] >= 48 && str[i] <= 57)
			result = result * 10 + str[i++] - 48;
	}
	return (result * n);
}