/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_xp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:00:08 by woopark           #+#    #+#             */
/*   Updated: 2021/12/05 11:09:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_x_sub(unsigned int h, int *len, int flag)
{
	unsigned char	chr;

	if (h == 0)
		return ;
	(*len)++;
	write_x_sub(h / 16, len, flag);
	chr = h % 16;
	if (chr < 10)
		chr += '0';
	else
	{
		if (flag == 0)
			chr += 'a' - 10;
		else
			chr += 'A' - 10;
	}
	write(1, &chr, 1);
}

int	write_x(unsigned int hex, int flag)
{
	int		len;

	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	len = 0;
	write_x_sub(hex, &len, flag);
	return (len);
}

void	write_p_sub(unsigned long long int p, int *len)
{
	unsigned char	chr;

	if (p == 0)
	{
		write(1, "0x", 2);
		return ;
	}
	++(*len);
	write_p_sub(p / 16, len);
	chr = p % 16;
	if (chr < 10)
		chr += '0';
	else
		chr += 'a' - 10;
	write(1, &chr, 1);
}

int	write_p(unsigned long long int p)
{
	int	len;

	if (p == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	len = 0;
	write_p_sub(p, &len);
	return (len + 2);
}