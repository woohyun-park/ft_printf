#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_intmax(void)
{
	char	*result;

	result = (char *)malloc(12);
	if (result == 0)
		return (NULL);
	result[0] = '-';
	result[1] = '2';
	result[2] = '1';
	result[3] = '4';
	result[4] = '7';
	result[5] = '4';
	result[6] = '8';
	result[7] = '3';
	result[8] = '6';
	result[9] = '4';
	result[10] = '8';
	result[11] = 0;
	return (result);
}

static int	ft_intlen(int n)
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

void	assign_sign(int n, char *result, int n_new)
{
	if (n < 0)
		result[0] = '-';
	else
		result[0] = n_new % 10 + '0';
}

char	*ft_itoa(int n)
{
	int		len;
	char	*result;
	int		i;
	int		n_new;

	if (n == -2147483648)
		return (ft_intmax());
	len = ft_intlen(n);
	result = (char *)malloc(ft_intlen(n) + 1);
	if (!result)
		return (NULL);
	result[len] = 0;
	if (n < 0)
		n_new = -n;
	else
		n_new = n;
	i = len - 1;
	while (i > 0)
	{
		result[i] = n_new % 10 + '0';
		n_new /= 10;
		i--;
	}
	assign_sign(n, result, n_new);
	return (result);
}
