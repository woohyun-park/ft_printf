#include "ft_printf.h"

static int	format(va_list ap, const char **str)
{
	int result;

	result = 0;
	if (**str == 'c')
		result = write_c(va_arg(ap, int));
	if (**str == 's')
		result = write_s(va_arg(ap, char *));
	if (**str == 'p')
		result = write_p(va_arg(ap, unsigned long long int));
	if (**str == 'd')
		result = write_diu(va_arg(ap, long long int), 0);
	if (**str == 'i')
		result = write_diu(va_arg(ap, long long int), 1);
	if (**str == 'u')
		result = write_diu(va_arg(ap, long long int), 2);
	if (**str == 'x')
		result = write_xp(va_arg(ap, unsigned long long int), 0, 1);
	if (**str == 'X')
		result = write_xp(va_arg(ap, unsigned long long int), 1, 1);
	if (**str == '%')
		result = write(1, "%", 1);
	(*str)++;
	return (result);
}

int			ft_printf(const char *str, ...)
{
	va_list	ap;
	int		num_result;

	if (str == 0)
		return (-1);
	num_result = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str != '%')
		{
			write(1, str++, 1);
			num_result++;
		}
		else
		{
			str++;
			num_result += format(ap, &str);
		}
	}
	va_end(ap);
	return (num_result);
}