/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_prec_wid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 14:06:28 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/04 19:30:00 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_precision(t_struct *parts)
{
	int		i;
	int		j;
	char	*tmp;

	if (ft_strlen(parts->string) > 1 && ft_strrchr(parts->string, '.'))
	{
		i = ft_strlen(parts->string) - 1;
		while (i >= 0)
		{
			if (parts->string[i - 1] == '.')
				break ;
			i--;
		}
		j = i;
		while (ft_isdigit(parts->string[j]))
			j++;
		tmp = ft_strsub(parts->string, i, (size_t)(j - i));
		parts->prec = ft_atoi(tmp);
		free(tmp);
	}
}

void	ft_fill_width(t_struct *parts)
{
	int		i;
	int		j;

	i = (int)ft_strlen(parts->string) - 1;
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

void	ft_fill_prec_wid(t_struct *parts)
{
	ft_fill_precision(parts);
	ft_fill_width(parts);
}
