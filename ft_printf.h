/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 07:49:10 by lemarque          #+#    #+#             */
/*   Updated: 2021/09/27 08:30:08 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<unistd.h>
# include<stdarg.h>
# include<stdlib.h>

int		ft_printf(const char *s, ...);
char	*ft_strchr(const char *str, int c);
int		ft_putchar(int c);
int		ft_putstr(char *str);
char	*ft_itoa(int num);
int		ft_putdi(int c);
int		ft_putui(unsigned int c);
char	*ft_itoa_base(unsigned long int num, char *base);
int		ft_putux(char type, unsigned int c);
int		ft_put_p(unsigned long int c);
#endif
