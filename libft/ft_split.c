/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 21:45:22 by almeliky          #+#    #+#             */
/*   Updated: 2023/02/27 15:53:17 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcounter(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] || (!s[i] && s[i - 1] != c))
			count++;
	}
	return (count);
}

char	*ft_subword(char const *s, char c, int num)
{
	int		i;
	int		k;
	char	*word;

	i = 0;
	k = 0;
	while (s[i] && num-- >= 0)
	{
		k = 0;
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			k++;
		}	
	}
	word = ft_substr(s, i - k, k);
	return (word);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		count;
	char	**arr;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_wordcounter(s, c);
	arr = malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (NULL);
	while (i < count)
	{
		arr[i] = ft_subword(s, c, i);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
