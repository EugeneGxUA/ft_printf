/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:55:14 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:22:41 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_wid(int len_wid)
{
	while (len_wid > 0)
	{
		ft_putchar_count(' ');
		len_wid--;
	}
}

static void		ft_print_pp(int len_wid, int len_prec,
						t_struct *parts)
{
	ft_print_wid(len_wid);
	ft_putstr_count("0x");
	while (len_prec > 0)
	{
		ft_putchar_count('0');
		len_prec--;
	}
	if (parts->arg_str[0] == '0' && parts->arg_str[1] == '\0'
											&& parts->prec == 0)
		return ;
	else
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_p_with_min(int len_wid,
						int len_prec, t_struct *parts)
{
	ft_putstr_count("0x");
	if (len_wid > 0 || len_prec > 0)
	{
		while (len_prec > 0)
		{
			ft_putchar_count('0');
			len_prec--;
		}
		if (parts->prec != 0)
			ft_putstr_count(parts->arg_str);
		ft_print_wid(len_wid);
	}
	else
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_p(t_struct *parts, int len_prec, int len_wid)
{
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec == 0)
		len_wid = parts->wid - (int)ft_strlen(parts->arg_str);
	if (parts->flag_minus == 1)
		ft_print_p_with_min(len_wid, len_prec, parts);
	if (parts->flag_minus == 0)
		ft_print_pp(len_wid, len_prec, parts);
}

void			ft_print_p_type(t_struct *parts, va_list arg)
{
	int			len_prec;
	int			len_wid;

	parts->arg_str = ft_itoa_base_unsigned(va_arg(arg, uintmax_t), 16);
	ft_tolowstr(parts->arg_str);
	len_wid = 0;
	len_prec = 0;
	if (parts->wid >= 2)
		parts->wid -= 2;
	if (parts->flag_zero == 1 && parts->flag_minus == 0 && parts->prec <= 0)
	{
		parts->prec = 0;
		parts->prec += parts->wid;
		parts->wid = 0;
	}
	if (parts->prec >= (int)ft_strlen(parts->arg_str))
		len_prec = parts->prec - ((int)ft_strlen(parts->arg_str));
	if (parts->wid <= ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = 0;
	if (parts->wid > ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = parts->wid - ((int)ft_strlen(parts->arg_str) + len_prec);
	ft_print_p(parts, len_prec, len_wid);
}
