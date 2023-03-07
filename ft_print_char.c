/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 18:31:07 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/07 18:31:07 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int ft_print_str(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}