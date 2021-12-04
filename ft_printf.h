/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woopark <woopark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:00:02 by woopark           #+#    #+#             */
/*   Updated: 2021/12/04 18:00:02 by woopark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);

int		write_c(char c);
int		write_s(char *s);
int		write_p(unsigned long long int num);
int		write_diu(long long int num, int flag);
int		write_x(unsigned long int num, int isUpper, int isX);

int		ft_printf(const char *str, ...);

#endif
