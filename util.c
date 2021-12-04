#include "ft_printf.h"

static unsigned int	ft_intlen(unsigned int n)
{
	unsigned int	result;

	if (n <= 0)
		result = 1;
	else
		result = 0;
	while (n != 0)
	{
		n /= 10;
		result++;
	}
	return (result);
}

char	*ft_itoa_u(unsigned int n)
{
	unsigned int		len;
	char				*result;
	unsigned int		i;

	len = ft_intlen(n);
	result = (char *)malloc(ft_intlen(n) + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	i = len - 1;
	while (i > 0)
	{
		result[i] = n % 10 + '0';
		n /= 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	else
		result[0] = n % 10 + '0';
	return (result);
}
