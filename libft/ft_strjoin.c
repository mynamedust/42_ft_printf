/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:50:24 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/21 18:51:52 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*point;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	point = malloc(len + 1);
	if (!point)
		return (NULL);
	len = 0;
	while (s1[len++])
		point[len - 1] = s1[len - 1];
	len = 0;
	while (s2[len++])
		point[ft_strlen(s1) + len - 1] = s2[len - 1];
	point[ft_strlen(s1) + len - 1] = '\0';
	return (point);
}
