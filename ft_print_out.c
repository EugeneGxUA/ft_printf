/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 16:04:54 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 21:49:44 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_wid(t_struct *parts, int len_wid)
{
	while (len_wid > 0)
	{
		if (parts->flag_zero == 0)
			ft_putchar_count(' ');
		if (parts->flag_zero == 1)
			ft_putchar_count('0');
		len_wid--;
	}
}

static void		ft_print_char(t_struct *parts, int len_wid)
{
	if (parts->flag_minus == 0)
	{
		ft_print_wid(parts, len_wid);
		if (parts->arg_str[0] == '\0')
			ft_putchar_count('\0');
		else
			ft_putstr_count(parts->arg_str);
	}
	else if (parts->flag_minus == 1)
	{
		if (parts->arg_str[0] == '\0')
			ft_putchar_count('\0');
		else
			ft_putstr_count(parts->arg_str);
		ft_print_wid(parts, len_wid);
	}
}

void			ft_print_out_char(t_struct *parts)
{
	int			len_wid;

	len_wid = 0;
	if (parts->wid <= (int)ft_strlen(parts->arg_str))
		len_wid = 0;
	else if (parts->wid > (int)ft_strlen(parts->arg_str))
		len_wid = (parts->wid - 1);
	ft_print_char(parts, len_wid);
}

void			ft_print_out(va_list arg, t_struct *parts)
{
	if (ft_strchr("c", parts->type) || ft_strchr("C", parts->type))
		ft_print_out_char(parts);
	else if (parts->type == 's')
		ft_print_out_string(parts);
	else if (parts->type == 'S')
		ft_print_out_string(parts);
	else if (ft_strchr("dDi", parts->type) != NULL)
		ft_print_did_digits(parts);
	else if (ft_strchr("oOuUxX", parts->type) != NULL)
		ft_print_oux_digits(parts);
	else if (ft_strchr("p", parts->type) != NULL)
		ft_print_p_type(parts, arg);
}
