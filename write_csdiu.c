/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_csdiu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:00:29 by woopark           #+#    #+#             */
/*   Updated: 2021/12/05 10:21:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		arg = ft_itoa_u((unsigned int)num);
	if (arg == NULL)
		return (-1);
	len = ft_strlen(arg);
	write(1, arg, len);
	free(arg);
	return (len);
}
