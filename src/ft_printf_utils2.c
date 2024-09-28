/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:31:41 by antonio-          #+#    #+#             */
/*   Updated: 2024/09/28 13:31:43 by antonio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

char	ft_toupper(char c)
{
	if (c <= 122 && c >= 97)
		c = c - 32;
	return (c);
}

void	ft_strmayus(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
}

void	basenum(unsigned long num, char *base, char *str)
{
	if (num >= ft_strlen(base))
	{
		basenum(num / ft_strlen(base), base, str);
		ft_strfiller(str, (base[num % ft_strlen(base)]));
	}
	if (num <= ft_strlen(base))
		ft_strfiller(str, base[num]);
}

int	check_hexsize(unsigned long nbr)
{
	int					size;
	unsigned long		num;

	num = nbr;
	size = 0;
	while (num >= 16)
	{
		num = num / 16;
		size++;
	}
	return (size + 1);
}

char	*ft_tohex(unsigned long nbr)
{
	char		*base;
	char		*str;

	base = "0123456789abcdef";
	str = ft_calloc(check_hexsize(nbr) + 1, 1);
	basenum(nbr, base, str);
	return (str);
}
