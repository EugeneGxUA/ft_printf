/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_for_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 11:26:48 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:05:35 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_len(t_struct *parts)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (parts->string[i] != '\0')
	{
		if (ft_strchr(" _+-#.lhjz", parts->string[i]) ||
				ft_isdigit(parts->string[i]))
			i++;
		else
		{
			i++;
			len++;
		}
	}
	return (len);
}

static void		ft_fill_wid(t_struct *parts)
{
	int			i;
	int			j;

	i = (int)ft_strlen(parts->string);
	while (i >= 0)
	{
		if (ft_isdigit(parts->string[i]))
		{
			j = i + 1;
			while (ft_isdigit(parts->string[i]))
			{
				if ((!ft_isdigit(parts->string[i - 1])
							&& parts->string[i - 1] != '.') || i == 0)
				{
					parts->wid = ft_atoi(ft_strsub(parts->string, i,
								(size_t)(j - i)));
					if (parts->wid > 0 || parts->wid < -1)
						return ;
				}
				i--;
			}
		}
		i--;
	}
}

static void		ft_rec(t_struct *parts)
{
	int			i;
	int			a;

	i = 0;
	a = 0;
	parts->arg_str = (char*)malloc(sizeof(char) * ft_len(parts) + 1);
	while (parts->string[i] != '\0' && parts->string[i] != '%')
	{
		if (ft_strchr(" _+-#.lhjz", parts->string[i]) ||
				ft_isdigit(parts->string[i]))
			i++;
		else
			break ;
	}
	while (parts->string[i] != '\0')
		parts->arg_str[a++] = parts->string[i++];
	parts->arg_str[a] = '\0';
	ft_rec_unb_type(parts);
	ft_fill_wid(parts);
	ft_zero_flag(parts);
	ft_minus_flag(parts);
}

static void		ft_init(char **s, int i, t_struct *parts)
{
	int			a;
	int			b;

	a = 0;
	b = 0;
	parts->string = (char*)malloc(sizeof(char) * i + 1);
	while (a <= i && **s != '\0' && **s != '%')
	{
		parts->string[a] = **s;
		a++;
		(*s)++;
	}
	parts->string[a] = '\0';
}

void			ft_check_for_type(char **s, t_struct *parts)
{
	int			i;

	i = 0;
	while ((*s)[i] != '\0' && (*s)[i] != '%')
		i++;
	ft_init(s, i, parts);
	ft_rec(parts);
	ft_print_ub(parts);
	return ;
}
