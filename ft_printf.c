/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:59:33 by woopark           #+#    #+#             */
/*   Updated: 2021/12/05 11:10:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	format(va_list ap, const char **str)
{
	int	result;

	result = 0;
	if (**str == 'c')
		result = write_c(va_arg(ap, int));
	else if (**str == 's')
		result = write_s(va_arg(ap, char *));
	else if (**str == 'p')
		result = write_p(va_arg(ap, unsigned long long int));
	else if (**str == 'd')
		result = write_diu(va_arg(ap, long long int), 0);
	else if (**str == 'i')
		result = write_diu(va_arg(ap, long long int), 1);
	else if (**str == 'u')
		result = write_diu(va_arg(ap, long long int), 2);
	else if (**str == 'x')
		result = write_x(va_arg(ap, unsigned int), 0);
	else if (**str == 'X')
		result = write_x(va_arg(ap, unsigned int), 1);
	else if (**str == '%')
		result = write(1, "%", 1);
	(*str)++;
	return (result);
}

int	ft_printf(const char *str, ...)
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
