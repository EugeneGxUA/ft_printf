/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_wint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 20:24:16 by egaragul          #+#    #+#             */
/*   Updated: 2017/03/05 23:14:28 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_wintlen(wint_t *str)
{
	unsigned int		len;
	int					i;

	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			len += 1;
		else if (str[i] <= 0x7FF)
			len += 2;
		else if (str[i] <= 0xFFFF)
			len += 3;
		else if (str[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}

static char				*ft_to_rec(char *dest, wint_t *str, int *i, int *a)
{
	if (str[*i] <= 0xFFFF)
	{
		dest[(*a)++] = (char)(((str[*i] & 0xF000) >> 12) + 0xE0);
		dest[(*a)++] = (char)(((str[*i] & 0x0Fc0) >> 6) + 0x80);
		dest[(*a)++] = (char)((str[*i] & 0x003F) + 0x80);
	}
	else if (str[*i] <= 0x10FFFF)
	{
		dest[(*a)++] = (char)(((str[*i] & 0x1c0000) >> 18) + 0xF0);
		dest[(*a)++] = (char)(((str[*i] & 0x03F000) >> 12) + 0x80);
		dest[(*a)++] = (char)(((str[*i] & 0x0Fc0) >> 6) + 0x80);
		dest[(*a)++] = (char)((str[*i] & 0x003F) + 0x80);
	}
	return (dest);
}

static char				*ft_rec(char *dest, wint_t *str)
{
	int					i;
	int					a;

	i = 0;
	a = 0;
	while (str[i])
	{
		if (str[i] <= 0x7F)
			dest[a++] = str[i];
		else if (str[i] <= 0x7FF)
		{
			dest[a++] = (char)(((str[i] & 0x07c0) >> 6) + 0xc0);
			dest[a++] = (char)((str[i] & 0x003F) + 0x80);
		}
		else
			dest = ft_to_rec(dest, str, &i, &a);
		i++;
	}
	dest[a] = '\0';
	return (dest);
}

char					*ft_strdup_wint(wint_t *str)
{
	unsigned int		i;
	char				*dest;

	i = 0;
	if (!str)
	{
		dest = (char*)malloc(sizeof(char) * 7);
		dest = "(null)";
		return (dest);
	}
	dest = (char*)malloc(sizeof(*dest) * ft_wintlen(str) + 1);
	if (!dest)
		return (NULL);
	dest = ft_rec(dest, str);
	return (dest);
}
