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
	while (num / i != 0 && size++ >= 0)
		i *= 10;
	str = ft_calloc(size, 1);
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
	ft_putnbr_fd(num, 1);
	return (ft_strlen(ft_itoa(num)));
}

size_t	ft_print_uint(unsigned int num)
{
	ft_putuint_fd(num, 1);
	return (ft_strlen(ft_uitoa(num)));
}

void	ft_itohex(char *str, unsigned int num, int size)
{
	int	n;

	n = 0;
	while (num && --size >= 0)
	{
		n = num % 16;
		num /= 16;
		if (n == 10)
			str[size] = 'a';
		if (n == 11)
			str[size] = 'b';
		if (n == 12)
			str[size] = 'c';
		if (n == 13)
			str[size] = 'd';
		if (n == 14)
			str[size] = 'e';
		if (n == 15)
			str[size] = 'f';
		if (n > 15 || n < 10)
			str[size] = '0' + n;
	}
}

size_t	ft_print_hex(unsigned int num, int x)
{
	char			*str;
	unsigned int	n;
	int				size;

	n = num;
	size = 2;
	while (n && size++ >= 0)
		n = n / 16;
	str = ft_calloc(size);
	if (!str)
		return (NULL);
	str[0] = '0';
	ft_itohex(str, num, size);
	if (x)
	{
		while (--size >= 0)
			str[size] = ft_toupper(str[size]);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int main()
{
	unsigned int c = 4294967293;
	printf("%x\n", c);
}