#include "minitalk.h"

#include<stdio.h>

int	power(int base, int power)
{
	int res;

	res = 1;
	while (power >= 1)
	{
		res *= base;
		power--;
	}
	return (res);
}

int	get_char(char *bits)
{
	int	res;
	int	i;
	int	j;

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
  return (res);
}
