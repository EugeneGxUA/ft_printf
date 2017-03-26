/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_perc_rec_only.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 13:56:30 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:10:02 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_wid(t_struct *parts, int len_wid)
{
	while (len_wid > 0)
	{
		if (parts->flag_zero == 1)
			ft_putchar_count('0');
		if (parts->flag_zero == 0)
			ft_putchar_count(' ');
		len_wid--;
	}
}

static void		ft_print(t_struct *parts, int len_wid)
{
	if (parts->flag_minus == 0)
	{
		ft_print_wid(parts, len_wid);
		ft_putstr_count(parts->arg_str);
	}
	else if (parts->flag_minus == 1)
	{
		ft_putstr_count(parts->arg_str);
		ft_print_wid(parts, len_wid);
	}
}

static void		ft_print_perc(t_struct *parts)
{
	int			len_wid;

	len_wid = 0;
	if (parts->flag_minus == 1)
		parts->flag_zero = 0;
	if (parts->wid <= (int)ft_strlen(parts->arg_str))
		len_wid = 0;
	else if (parts->wid > (int)ft_strlen(parts->arg_str))
		len_wid = (parts->wid - 1);
	ft_print(parts, len_wid);
}

static void		ft_rec_arg_str(t_struct *parts)
{
	int			i;
	int			a;
	int			b;

	b = 0;
	i = 0;
	a = 0;
	while (parts->string[i] != '%' && parts->string[i] != '\0')
		i++;
	if (parts->string[i] == '\0')
		i--;
	parts->arg_str = (char*)malloc(sizeof(char) * i + 1);
	if (parts->string[i] == '%')
	{
		parts->type = parts->string[i];
		parts->arg_str[a++] = parts->string[i];
		parts->arg_str[a] = '\0';
	}
	ft_zero_flag(parts);
	ft_minus_flag(parts);
	ft_fill_prec_wid(parts);
	ft_print_perc(parts);
}

void			ft_for_perc_rec_only(char **s, t_struct *parts, int i)
{
	int			a;

	a = 0;
	if ((*s)[i] == '\0')
		i--;
	parts->string = (char*)malloc(sizeof(char) * i + 1);
	while (a <= i && (**s != '\0' || **s != '%'))
	{
		parts->string[a] = **s;
		(*s)++;
		a++;
	}
	ft_rec_arg_str(parts);
}
