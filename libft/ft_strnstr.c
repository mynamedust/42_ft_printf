/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:19:41 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/27 18:04:06 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	b;

	i = 0;
	b = 0;
	if (!haystack && !len)
		return (NULL);
	if (!needle[b])
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (needle[b] == haystack[i] && i < len)
		{
			if (b == ft_strlen(needle) - 1)
				return ((char *)haystack);
			i++;
			b++;
		}
		b = 0;
		i = 0;
		len--;
		haystack++;
	}
	return (NULL);
}
