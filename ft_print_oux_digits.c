/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_oux_digits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:20:14 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:21:23 by egaragul         ###   ########.fr       */
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

static void		ft_print_oux(int len_wid, int len_prec,
						t_struct *parts)
{
	if (parts->arg_str[0] != '0')
		ft_print_wid(len_wid);
	if (ft_strchr("oOxX", parts->type))
		ft_for_sharp(parts);
	while (len_prec > 0)
	{
		ft_putchar_count('0');
		len_prec--;
	}
	if (parts->arg_str[0] == '0' && parts->prec == 0)
	{
		if (len_wid > 0)
			ft_print_wid(len_wid + 1);
	}
	else if (ft_strcmp(parts->arg_str, "0") == 0 && parts->prec == 0)
		ft_for_nuls_and_spaces(parts);
	else if (!(parts->arg_str[0] == '0' && parts->flag_sharp
				== 1 && parts->wid < 0 && parts->prec < 0))
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_oux_with_min(int len_wid,
						int len_prec, t_struct *parts)
{
	int			symbol;

	symbol = 0;
	if (len_wid > 0 || len_prec > 0)
	{
		if (ft_strchr("oOxX", parts->type))
			ft_for_sharp(parts);
		while (len_prec > 0)
		{
			ft_putchar_count('0');
			len_prec--;
		}
		if (symbol == 45)
			ft_putstr_count(parts->arg_str + 1);
		else
			ft_putstr_count(parts->arg_str);
		ft_print_wid(len_wid);
	}
	else
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_oux_digit(t_struct *parts, int len_prec, int len_wid)
{
	int			symbol;

	symbol = 0;
	if (parts->flag_sharp == 1)
	{
		if (ft_strchr("oO", parts->type))
		{
			if (parts->wid < 0 && parts->prec > 0)
				len_prec--;
			len_wid -= 1;
		}
		else if (ft_strchr("xX", parts->type))
			len_wid -= 2;
	}
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec == 0)
		len_wid = parts->wid - (int)ft_strlen(parts->arg_str);
	if (parts->flag_minus == 1)
		ft_print_oux_with_min(len_wid, len_prec, parts);
	if (parts->flag_minus == 0)
		ft_print_oux(len_wid, len_prec, parts);
}

void			ft_print_oux_digits(t_struct *parts)
{
	int			len_prec;
	int			len_wid;

	len_wid = 0;
	len_prec = 0;
	if (parts->flag_zero == 1 && parts->flag_minus == 0 && parts->prec <= 0
												&& parts->flag_sharp == 1)
	{
		if (ft_strchr("oO", parts->type))
			parts->wid -= 1;
		else if (ft_strchr("xX", parts->type))
			parts->wid -= 2;
	}
	ft_for_did_digits_wid(parts);
	if (parts->prec >= (int)ft_strlen(parts->arg_str))
		len_prec = parts->prec - ((int)ft_strlen(parts->arg_str));
	if (parts->wid <= ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = 0;
	if (parts->wid > ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = parts->wid - ((int)ft_strlen(parts->arg_str) + len_prec);
	ft_print_oux_digit(parts, len_prec, len_wid);
}
