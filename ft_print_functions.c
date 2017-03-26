/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 19:30:20 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 22:27:04 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_count(char c)
{
	write(1, &c, 1);
	g_counter++;
}

void	ft_putstr_count(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		ft_putchar_count(str[i++]);
}

void	ft_putnbr_unsigned(uintmax_t nb)
{
	if (nb >= 10)
	{
		ft_putnbr_unsigned(nb / 10);
		ft_putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar_count(nb - '0');
}

char	*ft_tolowstr(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
