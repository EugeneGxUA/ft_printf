/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_unb_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:04:17 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 17:32:46 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_rec_unb_type(t_struct *parts)
{
	int		i;

	i = 0;
	while (parts->string[i] != '\0')
	{
		if (ft_strchr(" _+-#.lhjz", parts->string[i]) ||
				ft_isdigit(parts->string[i]))
			i++;
		else
			break ;
	}
	parts->type = parts->string[i];
}
