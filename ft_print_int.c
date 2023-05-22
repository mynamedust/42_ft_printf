/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:36:35 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/07 18:36:35 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint_fd(unsigned int n, int fd)
{
	unsigned int	num;
	char			c;

	num = n;
	if (fd < 0)
		return ;
	if (num >= 0)
	{
		c = '0' + (unsigned int)(num % 10);
		if (n == 0)
		{
			write(fd, "0", 1);
			return ;
		}
		if (num / 10 != 0)
			ft_putuint_fd(num / 10, fd);
		write(fd, &c, 1);
	}
}

char	*ft_uitoa(unsigned int n)
{
	char				*str;
	long unsigned int	i;
	long unsigned int	num;
	int					size;

	i = 1;
	size = 1;
	num = n;
	while (num / i > 0)
	{
		i *= 10;
		size++;
	}
	str = ft_calloc(size + 1, 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	size = 0;
	while (i >= 10)
	{
		i /= 10;
		str[size++] = '0' + num / i;
		num %= i;
	}
	return (str);
}

size_t	ft_print_int(int num)
{
	size_t	i;
	char	*str;

	ft_putnbr_fd(num, 1);
	str = ft_itoa(num);
	i = ft_strlen(str);
	free(str);
	return (i);
}

size_t	ft_print_uint(unsigned int num)
{
	size_t	i;
	char	*str;

	ft_putuint_fd(num, 1);
	str = ft_uitoa(num);
	i = ft_strlen(str);
	free(str);
	return (i);
}
