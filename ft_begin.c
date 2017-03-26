/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_begin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:14:20 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/02 13:21:56 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_flags(t_struct *parts)
{
	ft_zero_flag(parts);
	ft_sharp_flag(parts);
	ft_space_flag(parts);
	ft_minus_flag(parts);
	ft_plus_flag(parts);
}

void	ft_begin(t_struct *parts, va_list arg)
{
	ft_fill_flags(parts);
	ft_fill_prec_wid(parts);
	if (ft_strchr("CS", parts->type) == NULL)
		ft_fill_modificators(parts);
	ft_what_type_print(arg, parts);
	ft_fill_prec_wid(parts);
	ft_print_out(arg, parts);
}
