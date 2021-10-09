/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:29:25 by lemarque          #+#    #+#             */
/*   Updated: 2021/10/09 18:47:20 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int static	ft_call_types(char c, va_list types)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count += ft_putchar(va_arg(types, int));
	else if (c == 's')
		char_count += ft_putstr(va_arg(types, char *));
	else if (c == 'p')
		char_count += ft_put_p(va_arg(types, unsigned long int));
	else if (c == 'd' || c == 'i')
		char_count += ft_putdi(va_arg(types, int));
	else if (c == 'u' || c == 'x' || c == 'X')
		char_count += ft_putux(c, va_arg(types, unsigned int));
	else if (c == '%')
		char_count += ft_putchar('%');
	return (char_count);
}

int	ft_printf(const char *s, ...)
{
	int		char_count;
	va_list	types;

	va_start(types, s);
	char_count = 0;
	while (*s)
	{
		if (*s == '%' && ft_strchr("cspdiuxX%", s[1]) && s++)
			char_count += ft_call_types(*s, types);
		else
		{
			write(1, s, 1);
			char_count++;
		}
		s++;
	}
	va_end(types);
	return (char_count);
}
