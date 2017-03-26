/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oux_digits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:20:14 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 16:57:20 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_wid(int len_wid, t_struct *parts)
{
	while (len_wid > 0)
	{
		if (parts->flag_zero == 1)
			ft_putchar_count('0');
		else if (parts->flag_zero == 0)
			ft_putchar_count(' ');
		len_wid--;
	}
}

static void		ft_print_str(int len_wid, int len_prec,
						t_struct *parts)
{
	int		i;

	i = 0;
	ft_print_wid(len_wid, parts);
	if (len_prec > 0 && parts->arg_str[i] != '\0')
	{
		while (len_prec > 0 && parts->arg_str[i] != '\0')
		{
			ft_putchar_count(parts->arg_str[i++]);
			len_prec--;
		}
	}
	else if (parts->prec != 0)
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_str_with_min(int len_wid,
						int len_prec, t_struct *parts)
{
	int		i;

	i = 0;
	if (parts->prec < 0)
		ft_putstr_count(parts->arg_str);
	if (len_wid > 0 || len_prec > 0)
	{
		while (len_prec > 0 && parts->arg_str[i] != '\0')
		{
			ft_putchar_count(parts->arg_str[i++]);
			len_prec--;
		}
		ft_print_wid(len_wid, parts);
	}
}

static void		ft_print_string(t_struct *parts, int len_prec, int len_wid)
{
	if (parts->flag_minus == 1)
		parts->flag_zero = 0;
	if (parts->flag_minus == 1)
		ft_print_str_with_min(len_wid, len_prec, parts);
	if (parts->flag_minus == 0)
		ft_print_str(len_wid, len_prec, parts);
}

void			ft_print_out_string(t_struct *parts)
{
	int			len_prec;
	int			len_wid;

	len_wid = 0;
	len_prec = 0;
	if (parts->prec < (int)ft_strlen(parts->arg_str) && parts->prec != -1)
		len_prec = parts->prec;
	if (parts->wid <= len_prec && len_prec > 0)
		len_wid = 0;
	if (parts->prec > (int)ft_strlen(parts->arg_str))
		parts->prec = -1;
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec < 0)
		len_wid = parts->wid - (int)ft_strlen(parts->arg_str);
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec > 0)
		len_wid = parts->wid - len_prec;
	if (parts->wid > len_prec && len_prec > 0)
		len_wid = parts->wid - len_prec;
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec == 0)
		len_wid = parts->wid;
	if (parts->wid > 0 && (ft_strcmp(parts->arg_str, "(null)") == 0))
		len_wid = parts->wid;
	ft_print_string(parts, len_prec, len_wid);
}
