#include "ft_printf.h"

int	write_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	write_s(char *s)
{
	int		result;

	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	result = 0;
	while (s[result])
		result++;
	write(1, s, result);
	return (result);
}

int	write_diu(long long int	num, int flag)
{
	char			*arg;
	char			len;

	if (flag == 0 || flag == 1)
		arg = ft_itoa((int)num);
	else
		arg = ft_itoa_u((unsigned long long int)num);
	len = ft_strlen(arg);
	write(1, arg, len);
	free(arg);
	return (len);
}
