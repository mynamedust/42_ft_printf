/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:45:09 by almeliky          #+#    #+#             */
/*   Updated: 2023/03/09 20:17:37 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

int		ft_print_char(int c);
int		ft_print_str(char *str);
void	ft_itohex(char *str, unsigned int num, int size);
size_t	ft_print_hex(unsigned int num, int x);
void	ft_putuint_fd(unsigned int n, int fd);
char	*ft_uitoa(unsigned int n);
size_t	ft_print_int(int num);
size_t	ft_print_uint(unsigned int num);
int		ft_typeprint(va_list *list, int c);
int		ft_printf(const char *str, ...);
size_t	ft_print_p(unsigned long long num, int x);
void	ft_itop(char *str, unsigned long long num, int size);
#endif