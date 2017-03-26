/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_did_digits.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 19:47:20 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:17:27 by egaragul         ###   ########.fr       */
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

static void		ft_print_did(int len_wid, int len_prec,
						t_struct *parts, int symbol)
{
	if (parts->flag_space == 1)
		ft_putchar_count(' ');
	ft_print_wid(len_wid);
	if (symbol == 45)
		ft_putchar_count('-');
	else if (parts->flag_plus == 1)
		ft_putchar_count('+');
	while (len_prec > 0)
	{
		ft_putchar_count('0');
		len_prec--;
	}
	if (parts->arg_str[0] == '0' && parts->prec == 0 && parts->wid > 0)
		parts->arg_str = ft_strdup(" ");
	else if (parts->arg_str[0] == '0' && parts->prec == 0 && parts->wid < 0)
		parts->arg_str = ft_strnew(1);
	if (symbol == 45)
		ft_putstr_count(parts->arg_str + 1);
	else if (symbol != 45)
		ft_putstr_count(parts->arg_str);
}

static void		ft_print_did_with_min(int len_wid,
						int len_prec, t_struct *parts, int symbol)
{
	if (parts->flag_space == 1)
		ft_putchar_count(' ');
	if (len_wid > 0 || len_prec > 0)
	{
		if (symbol == 45)
			ft_putchar_count('-');
		else if (parts->flag_plus == 1)
			ft_putchar_count('+');
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

static void		ft_print_did_digit(t_struct *parts, int len_prec, int len_wid)
{
	int			symbol;

	symbol = 0;
	if (parts->arg_str[0] == '-')
		symbol = 45;
	if (parts->wid > (int)ft_strlen(parts->arg_str) && parts->prec == 0)
		len_wid = parts->wid - (int)ft_strlen(parts->arg_str);
	if (parts->flag_plus == 1 && parts->arg_str[0] != '-')
		len_wid -= 1;
	if (parts->flag_space == 1)
		len_wid -= 1;
	if (parts->flag_minus == 1)
		ft_print_did_with_min(len_wid, len_prec, parts, symbol);
	if (parts->flag_minus == 0)
		ft_print_did(len_wid, len_prec, parts, symbol);
}

void			ft_print_did_digits(t_struct *parts)
{
	int			len_prec;
	int			len_wid;

	len_wid = 0;
	len_prec = 0;
	if (parts->prec >= 0)
		parts->flag_zero = 0;
	if (parts->flag_zero == 1 && parts->flag_minus == 0 && parts->prec <= 0
						&& (parts->flag_plus == 1 || parts->flag_space == 1))
	{
		parts->wid -= 1;
	}
	ft_for_did_digits_wid(parts);
	if (parts->prec >= (int)ft_strlen(parts->arg_str))
	{
		if (parts->arg_str[0] == '-')
			len_prec = parts->prec - (((int)ft_strlen(parts->arg_str) - 1));
		else
			len_prec = parts->prec - ((int)ft_strlen(parts->arg_str));
	}
	if (parts->wid <= ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = 0;
	if (parts->wid > ((int)ft_strlen(parts->arg_str) + len_prec))
		len_wid = parts->wid - ((int)ft_strlen(parts->arg_str) + len_prec);
	ft_print_did_digit(parts, len_prec, len_wid);
}
