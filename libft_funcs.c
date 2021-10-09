/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:29:49 by lemarque          #+#    #+#             */
/*   Updated: 2021/10/08 18:22:13 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	char_count;

	char_count = 0;
	if (str == NULL)
		str = "(null)";
	while (*str)
	{
		write(1, str++, 1);
		char_count++;
	}
	return (char_count);
}

char	*ft_itoa(int num)
{
	long long int	new_num;
	int				count;
	int				sign;
	char			*str_num;

	new_num = num;
	count = 1;
	sign = num < 0;
	if (sign)
		new_num *= -1;
	while (num / 10 != 0 && ++count)
		num /= 10;
	str_num = malloc(sizeof(char) * (sign + count + 1));
	if (!str_num)
		return (0);
	if (sign)
		str_num[0] = '-';
	str_num[sign + count] = '\0';
	while (count--)
	{
		str_num[sign + count] = (new_num % 10) + '0';
		new_num /= 10;
	}
	return (str_num);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_itoa_base(unsigned long int num, char *base)
{
	unsigned long int		new_num;
	char					*str_num;
	int						count;
	int						i;
	int						base_size;

	new_num = num;
	count = 1;
	i = 0;
	base_size = 0;
	while (base[base_size] != '\0')
		base_size++;
	while (num / base_size != 0 && ++count)
		num /= base_size;
	str_num = malloc(sizeof(char) * (count + 1));
	if (!str_num)
		return (0);
	i = count;
	while (i--)
	{
		str_num[i] = base[new_num % base_size];
		new_num /= base_size;
	}
	str_num[count] = '\0';
	return (str_num);
}
