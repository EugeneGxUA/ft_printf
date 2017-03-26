/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:29:14 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/03 14:26:04 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Функция поиска '0' - Если в строке, после '%' до type символ '0'
** и предыдущий элемент не число, то данный '0' - флаг
**
** Функции поиска остальных флагов - Если в строке, после '%' до type
** символ '#', ' ', '-', '+', то мы отмечаем это в соответствующей переменной
** структуры
*/

void	ft_zero_flag(t_struct *parts)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (parts->string[i] != parts->type)
	{
		if (parts->string[i - 1] == '.' && ft_isdigit(parts->string[i]))
		{
			while (ft_isdigit(parts->string[i]))
				i++;
			i--;
			flag = 1;
		}
		if (parts->string[i] == '0' && !ft_isdigit(parts->string[i - 1])
			&& flag == 0)
		{
			parts->flag_zero = 1;
			break ;
		}
		flag = 0;
		i++;
	}
}

void	ft_sharp_flag(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != parts->type)
	{
		if (parts->string[i] == '#')
		{
			parts->flag_sharp = 1;
			break ;
		}
		i++;
	}
}

void	ft_space_flag(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != parts->type)
	{
		if (parts->string[i] == ' ')
		{
			parts->flag_space = 1;
			break ;
		}
		i++;
	}
}

void	ft_minus_flag(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != parts->type)
	{
		if (parts->string[i] == '-')
		{
			parts->flag_minus = 1;
			break ;
		}
		i++;
	}
}

void	ft_plus_flag(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != parts->type)
	{
		if (parts->string[i] == '+')
		{
			parts->flag_plus = 1;
			break ;
		}
		i++;
	}
}
