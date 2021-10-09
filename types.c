/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 07:46:52 by lemarque          #+#    #+#             */
/*   Updated: 2021/10/08 18:00:10 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putdi(int c)
{
	char	*string;
	int		i;

	string = ft_itoa(c);
	i = ft_putstr(string);
	free(string);
	return (i);
}

int	ft_putux(char type, unsigned int c)
{
	char	*string;
	int		i;

	string = NULL;
	i = 0;
	if (type == 'X')
		string = ft_itoa_base(c, "0123456789ABCDEF");
	else if (type == 'x')
		string = ft_itoa_base(c, "0123456789abcdef");
	else if (type == 'u')
		string = ft_itoa_base(c, "0123456789");
	i += ft_putstr(string);
	free(string);
	return (i);
}

int	ft_put_p(unsigned long int c)
{
	int		i;
	char	*string;

	string = NULL;
	i = 0;
	i += ft_putstr("0x");
	string = ft_itoa_base(c, "0123456789abcdef");
	i += ft_putstr(string);
	free(string);
	return (i);
}
