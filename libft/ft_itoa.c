/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 18:29:54 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/24 16:09:47 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_abs(long int num)
{
	if (num < 0)
		num = -1 * num;
	return (num);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	i;
	long int	num;
	int			size;

	i = 1;
	size = 2;
	num = n;
	while (num / i != 0 && size++ >= 0)
		i *= 10;
	str = ft_calloc(size, 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	size = 0;
	if (num < 0)
		str[size++] = '-';
	num = ft_abs(num);
	while (i >= 10)
	{
		i /= 10;
		str[size++] = '0' + num / i;
		num %= i;
	}
	return (str);
}
