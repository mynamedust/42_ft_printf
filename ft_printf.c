/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:30:28 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/09 17:30:28 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_typeprint(va_list *list, int c)
{
	size_t	number;

	number = 0;
	if (c == 'c')
		number = ft_print_char(va_arg(*list, int));
	if (c == 's')
		number = ft_print_str(va_arg(*list, char *));
	if (c == 'p')
	{
		write(1, "0x", 2);
		number = 2 + ft_print_p(va_arg(*list, unsigned long long), 0);
	}	
	if (c == 'd' || c == 'i')
		number = ft_print_int(va_arg(*list, int));
	if (c == 'u')
		number = ft_print_uint(va_arg(*list, unsigned int));
	if (c == 'x')
		number = ft_print_hex(va_arg(*list, unsigned int), 0);
	if (c == 'X')
		number = ft_print_hex(va_arg(*list, unsigned int), 1);
	if (c == '%')
		number = ft_print_char('%');
	return ((int)number);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		number;

	number = 0;
	i = 0;
	va_start(list, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			number += ft_typeprint(&list, str[i]);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			number++;
		}
		i++;
	}
	va_end(list);
	return (number);
}
