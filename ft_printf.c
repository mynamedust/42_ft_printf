#include <stdio.h>
#include <stdarg.h>

int	ft_typeprint(va_list *list, int c)
{
	int	number;

	number = 0;
	switch (c)
	{
		case 'c' || :
			number = ft_print_char(va_arg(*list, int));
		case 's':
			number = ft_print_str(va_arg(*list, char *));
		case 'p':
			// number = ft_print_char(va_arg(*list, int));
		case 'd':
			number = ft_print_int(va_arg(*list, int));
		case 'i':
			number = ft_print_int(va_arg(*list, int));
		case 'u':
			number = ft_print_uint(va_arg(*list, unsigned int));
		case 'x':
			number = ft_print_hex(va_arg(*list, unsigned int));
		case 'X':
			number = ft_print_hex(va_arg(*list, unsigned int));
		case '%':
			number = ft_print_char('%');
	}
	return (number);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	list;
	int		number;

	va_start(list, str);
	while (str[i])
	{
		if (str[i++] == '%')
			number += ft_typeprint(&list, str[i]);
		else
		{
			ft_putchar_fd(str[i]);
			number++;
		}
		i++;
	}
	va_end(list);
	return (number);
}

int	main()
{
	unsigned int	d = 4294967295;
	char s[] = "STRING";
	printf("addd wwqe qwe %d asd %d qwe %% ", ftft(d));
}