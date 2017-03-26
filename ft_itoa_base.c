/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:56:43 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:13:50 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int						ft_len(unsigned long long tmp, int base)
{
	int							i;

	i = 0;
	while (tmp > 0)
	{
		tmp /= (unsigned long long)base;
		i++;
	}
	return (i);
}

static char						ft_record(unsigned long long tmp)
{
	if (tmp >= 10)
		return (tmp - 10 + 'A');
	else
		return (tmp + '0');
}

static unsigned long long		ft_to_uns(long long value)
{
	unsigned long long			tmp;

	if (value < 0)
		return ((tmp = (unsigned long long)value * -1));
	else
		return ((tmp = (unsigned long long)value));
}

char							*ft_itoa_base(long long value, int base)
{
	int							i;
	unsigned long long			tmp;
	char						*str;

	if (base < 2 || base > 16)
		return (NULL);
	tmp = ft_to_uns(value);
	i = ft_len(tmp, base);
	if (value <= 0)
		i++;
	str = (char*)malloc(sizeof(char) * i + 1);
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = ft_record(tmp % (unsigned long long)base);
		i--;
		tmp /= (unsigned long long)base;
	}
	if (value < 0 && base == 10)
		str[0] = '-';
	return (str);
}
