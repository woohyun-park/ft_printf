#include "ft_printf.h"

static int	write_result(int len, unsigned long int num, int isUpper)
{
	const char	*str_low = "0123456789abcdef";
	const char	*str_upp = "0123456789ABCDEF";
	char		*result;
	int			pos;

	result = (char *)malloc(sizeof(char) * (len + 1));
	result[len] = 0;
	pos = len;
	while (num > 0)
	{
		if (isUpper == 0)
			result[--pos] = str_low[num % 16];
		else
			result[--pos] = str_upp[num % 16];
		num /= 16;
	}
	write(1, result, len);
	free(result);
	return (len);
}

int	write_x(unsigned long int num, int isUpper, int isX)
{
	unsigned long int	tempNum;
	unsigned long int	len;

	if (isX == 1)
		tempNum = (unsigned int)num;
	else
		tempNum = num;
	if (tempNum == 0)
		return (write(1, "0", 1));
	len = 0;
	while (tempNum > 0)
	{
		tempNum /= 16;
		len++;
	}
	return (write_result(len, num, isUpper));
}

int	write_p(unsigned long long int num)
{
	int	result;

	result = 0;
	result += write(1, "0x", 2);
	if (num == 0)
		result += write(1, "0", 1);
	else
		result += write_x(num, 0, 0);
	return (result);
}
