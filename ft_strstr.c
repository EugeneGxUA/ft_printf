/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:23:21 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 22:23:45 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strstr(const char *big, const char *small)
{
	size_t		i;
	size_t		j;
	size_t		n;

	i = 0;
	j = 0;
	n = ft_strlen(small);
	if (n == 0)
		return ((char*)big);
	while (big[i])
	{
		while (big[i + j] == small[j] && small[j] != '\0')
		{
			if (j == n - 1)
				return ((char*)big + i);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}
