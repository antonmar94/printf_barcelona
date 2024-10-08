/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:30:03 by antonio-          #+#    #+#             */
/*   Updated: 2024/09/28 13:30:06 by antonio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

char	find_type(char *text)
{
	char	*types;
	char	*aux;
	int		i;

	types = "cspdiuxX%";
	aux = text;
	while (find_flag(aux) || (*aux >= 48 && *aux < 58))
		aux++;
	i = 0;
	while (*aux != types[i] && types[i])
		i++;
	if (types[i] == '\0')
		return (0);
	return (types[i]);
}

void	*find_por(char *text)
{
	char	*aux;

	aux = text;
	while (*aux != '%' && *aux)
		aux++;
	aux++;
	return (aux);
}

char	find_flag(char *text)
{
	char	*flags;
	char	*aux;
	int		i;

	flags = "-0.*";
	aux = text;
	i = 0;
	while (*aux != flags[i] && flags[i])
		i++;
	if (flags[i] == '\0')
		return (0);
	if (flags[i] == '0' && aux--)
	{
		if (*aux >= 48 && *aux < 58)
			return (0);
	}
	return (flags[i]);
}

int	find_this_flag(char *text, char flag)
{
	char	*aux;

	aux = text;
	while (find_flag(aux) || (*aux >= 48 && *aux < 58))
	{
		if (flag == '0' && find_flag(aux) == '.')
			return (0);
		if (find_flag(aux) == flag)
			return (1);
		aux++;
	}
	return (0);
}

char	first_flag(char *text)
{
	while (*text)
	{
		if (*text == '*')
			return ('*');
		if (*text == '.')
			return ('.');
		text++;
	}
	return (0);
}
