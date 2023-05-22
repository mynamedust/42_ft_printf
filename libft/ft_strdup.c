/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:36:55 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/27 18:03:11 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*point;

	i = 0;
	while (s1[i])
		i++;
	point = (char *)malloc(sizeof(char) * (i + 1));
	if (!point)
		return (NULL);
	i = 0;
	while (s1[i++])
		point[i - 1] = s1[i - 1];
	point[i - 1] = '\0';
	return (point);
}
