/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_did_digits_wid.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:50:39 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:08:51 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_for_nuls_and_spaces(t_struct *parts)
{
	if (parts->flag_zero == 1)
		ft_putchar_count('0');
	else
		ft_putchar_count(' ');
}

void	ft_for_sharp(t_struct *parts)
{
	if (parts->flag_sharp == 1)
	{
		if (ft_strchr("oO", parts->type))
			ft_putchar_count('0');
		else if (ft_strchr("x", parts->type))
		{
			ft_putchar_count('0');
			ft_putchar_count('x');
		}
		else if (ft_strchr("X", parts->type))
		{
			ft_putchar_count('0');
			ft_putchar_count('X');
		}
	}
}

void	ft_for_uox(t_struct *parts)
{
	if (ft_strchr("uU", parts->type))
	{
		parts->flag_sharp = 0;
		parts->flag_space = 0;
		parts->flag_plus = 0;
	}
	if (ft_strchr("oOxX", parts->type))
	{
		if (ft_strchr("xX", parts->type))
		{
			if (parts->arg_str[0] == '0' && parts->arg_str[1] == '\0')
				parts->flag_sharp = 0;
		}
		parts->flag_space = 0;
		parts->flag_plus = 0;
	}
}

void	ft_for_did_digits_wid(t_struct *parts)
{
	if (ft_strchr("uUoOxX", parts->type))
		ft_for_uox(parts);
	if (ft_strchr("diD", parts->type) && parts->flag_zero == 1 &&
			parts->flag_minus == 0 && parts->prec <= 0 && parts->arg_str[0]
			== '-' && parts->flag_plus == 0 && parts->flag_sharp == 0)
		parts->wid -= 1;
	if (parts->arg_str[0] == '-' && (parts->flag_plus == 1 ||
									parts->flag_space == 1))
	{
		parts->flag_plus = 0;
		parts->flag_space = 0;
	}
	if (parts->flag_plus == 1 && parts->flag_space == 1)
		parts->flag_space = 0;
	if (parts->flag_zero == 1 && parts->flag_minus == 0 && parts->prec <= 0)
	{
		parts->prec = 0;
		parts->prec += parts->wid;
		parts->wid = 0;
	}
	if (parts->flag_zero == 1 && parts->flag_minus == 1)
		parts->flag_zero = 0;
}
