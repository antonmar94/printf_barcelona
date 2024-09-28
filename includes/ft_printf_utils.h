/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonio- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 13:33:48 by antonio-          #+#    #+#             */
/*   Updated: 2024/09/28 13:33:55 by antonio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void				ft_putchar(char c);
unsigned int		ft_strlen(const char *str);
void				ft_putstr(char *s);
void				ft_strmayus(char *str);
void				ft_strfiller(char *str, char c);
char				*ft_strdup(const char *string);
void				*ft_calloc(size_t nitems, size_t size);
void				free_all(char *to_free);
void				basenum(unsigned long num, char *base, char *str);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_unsigned_itoa(unsigned int n);
int					check_hexsize(unsigned long nbr);
char				*ft_tohex(unsigned long nbr);

#endif
