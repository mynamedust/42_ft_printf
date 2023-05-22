/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:52:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/21 21:27:21 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	int		i;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	size = ft_strlen(s1);
	while (size - i > 0 && ft_strchr(set, s1[size - i]))
		i++;
	size -= i;
	i = 0;
	if (!size)
		return (ft_strdup(""));
	while (s1[i] && size && ft_strchr(set, s1[i]))
		i++;
	size -= i;
	str = ft_calloc(++size + 1, 1);
	if (!str)
		return (NULL);
	s1 = s1 + i;
	i = 0;
	while (size--)
		str[i++] = *(s1++);
	return (str);
}
