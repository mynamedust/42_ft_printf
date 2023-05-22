/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:52:58 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/09 20:16:58 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itohex(char *str, unsigned int num, int size)
{
	int	n;

	n = 0;
	while (num % 16 >= 0 && --size >= 0)
	{
		n = num % 16;
		num /= 16;
		if (n == 10)
			str[size] = 'a';
		if (n == 11)
			str[size] = 'b';
		if (n == 12)
			str[size] = 'c';
		if (n == 13)
			str[size] = 'd';
		if (n == 14)
			str[size] = 'e';
		if (n == 15)
			str[size] = 'f';
		if (n < 10)
			str[size] = '0' + n;
	}
}

size_t	ft_print_hex(unsigned int num, int x)
{
	char			*str;
	unsigned int	n;
	int				size;

	n = num;
	size = 1;
	while (n)
	{
		n = n / 16;
		size++;
	}
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (0);
	str[0] = '0';
	ft_itohex(str, num, size - 1);
	if (x)
	{
		while (--size >= 0)
			str[size] = ft_toupper(str[size]);
	}
	ft_putstr_fd(str, 1);
	size = (int)ft_strlen(str);
	free(str);
	return (size);
}

void	ft_itop(char *str, unsigned long long num, int size)
{
	int	n;

	n = 0;
	while (num % 16 >= 0 && --size >= 0)
	{
		n = num % 16;
		num /= 16;
		if (n == 10)
			str[size] = 'a';
		if (n == 11)
			str[size] = 'b';
		if (n == 12)
			str[size] = 'c';
		if (n == 13)
			str[size] = 'd';
		if (n == 14)
			str[size] = 'e';
		if (n == 15)
			str[size] = 'f';
		if (n < 10)
			str[size] = '0' + n;
	}
}

size_t	ft_print_p(unsigned long long num, int x)
{
	char				*str;
	unsigned long long	n;
	int					size;

	n = num;
	size = 1;
	while (n)
	{
		n = n / 16;
		size++;
	}
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (0);
	str[0] = '0';
	ft_itop(str, num, size - 1);
	if (x)
	{
		while (--size >= 0)
			str[size] = ft_toupper(str[size]);
	}
	ft_putstr_fd(str, 1);
	size = (int)ft_strlen(str);
	free(str);
	return (size);
}
