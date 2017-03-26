/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 13:47:44 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:23:53 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_wid(t_struct *parts)
{
	int			i;

	i = parts->wid;
	while (i > 0)
	{
		if (parts->flag_zero == 1)
			ft_putchar_count('0');
		if (parts->flag_zero == 0)
			ft_putchar_count(' ');
		i--;
	}
}

static void		ft_print_unb(t_struct *parts)
{
	ft_print_wid(parts);
	ft_putstr_count(parts->arg_str);
}

static void		ft_print_ub_with_min(t_struct *parts)
{
	int			i;
	int			flag;

	flag = 0;
	i = 0;
	while (parts->arg_str[i] != '\0')
	{
		if (parts->arg_str[i] == '\n')
		{
			flag = 1;
			i++;
		}
		else
		{
			ft_putchar_count(parts->arg_str[i]);
			i++;
		}
	}
	ft_print_wid(parts);
	if (flag == 1)
		ft_putchar_count('\n');
}

void			ft_print_ub(t_struct *parts)
{
	int			i;

	i = 0;
	if (parts->wid > 1)
		parts->wid--;
	if (parts->flag_minus == 1)
		parts->flag_zero = 0;
	if (parts->flag_minus == 0)
		ft_print_unb(parts);
	if (parts->flag_minus == 1)
		ft_print_ub_with_min(parts);
}
