/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_modificators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 15:48:09 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/02 18:19:10 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_detect_h(t_struct *parts)
{
	int		i;
	int		count_h;

	i = 0;
	while (parts->string[i] != '\0')
	{
		count_h = 0;
		while (parts->string[i] == 'h')
		{
			count_h++;
			i++;
		}
		if (count_h % 2 != 0)
			return (1);
		i++;
	}
	return (0);
}

void	ft_digit_mod(t_struct *parts)
{
	if (ft_strchr(parts->string, 'z'))
		parts->modif = ft_strdup("z");
	else if (ft_strchr(parts->string, 'j'))
		parts->modif = ft_strdup("j");
	else if (ft_strstr(parts->string, "ll") != 0)
		parts->modif = ft_strdup("ll");
	else if (ft_strchr(parts->string, 'l') || ft_strchr("DOU", parts->type))
		parts->modif = ft_strdup("l");
	else if (ft_strchr(parts->string, 'h') && ft_detect_h(parts) == 1)
		parts->modif = ft_strdup("h");
	else if (ft_strstr(parts->string, "hh") != 0)
		parts->modif = ft_strdup("hh");
}

void	ft_check_mod(t_struct *parts)
{
	if (ft_strchr("diouxXDOU", parts->type))
		ft_digit_mod(parts);
	else if (ft_strchr("cs", parts->type))
	{
		if (ft_strchr(parts->string, 'l'))
			parts->modif = ft_strdup("l");
	}
}

void	ft_fill_modificators(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != '\0')
	{
		if (ft_strchr("hljzDOU", parts->string[i]))
			ft_check_mod(parts);
		i++;
	}
}
