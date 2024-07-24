/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarenas- <aarenas-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 17:22:34 by aarenas-          #+#    #+#             */
/*   Updated: 2024/07/15 14:09:56 by aarenas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_putnbr_dec(long int nb, int *p_w)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', p_w);
		ft_printf_putnbr_dec(nb, p_w);
	}
	else if (nb > 9)
	{
		ft_printf_putnbr_dec((nb / 10), p_w);
		ft_printf_putnbr_dec((nb % 10), p_w);
	}
	else
	{
		ft_putchar(nb + '0', p_w);
	}
}

void	ft_printf_putnbr_hexa(unsigned long long nb, char c, int *p_w)
{
	char	*set;

	if (c == 'x')
		set = "0123456789abcdef";
	else if (c == 'X')
		set = "0123456789ABCDEF";
	if (nb > 15)
	{
		ft_printf_putnbr_hexa((nb / 16), c, p_w);
		ft_printf_putnbr_hexa((nb % 16), c, p_w);
	}
	else
	{
		ft_putchar(set[nb], p_w);
	}
}
