/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:48:50 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 22:22:15 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s)
		return (0);
	str = (char*)malloc(sizeof(*str) * len + 1);
	if (!str)
		return (0);
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
