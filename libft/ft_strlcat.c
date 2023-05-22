/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 16:39:22 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/20 21:26:06 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	y;

	if (!dst && dstsize == 0)
		return (0);
	i = ft_strlen(dst);
	y = 0;
	if (!dstsize || dstsize <= i)
		return (dstsize + ft_strlen(src));
	while (y < dstsize - i - 1 && src[y])
	{
		dst[i + y] = src[y];
		y++;
	}
	dst[i + y] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[y]));
}
