/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoury <anoury@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:53:20 by anoury            #+#    #+#             */
/*   Updated: 2022/06/01 18:54:13 by anoury           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char c)
{
	int	len;

	len = 0;
	if (nbr < 10)
		len += ft_putchar(nbr + 48);
	else if (nbr < 16)
	{
		if (c == 'x')
			len += ft_putchar(nbr + 87);
		if (c == 'X')
			len += ft_putchar(nbr + 55);
	}
	else
	{
		len += ft_putnbr_hex(nbr / 16, c);
		len += ft_putnbr_hex(nbr % 16, c);
	}
	return (len);
}

int	ft_putadd(unsigned long add)
{
	int	len;

	len = 0;
	if (add < 10)
		len += ft_putchar(add + 48);
	else if (add < 16)
		len += ft_putchar(add + 87);
	else
	{
		len += ft_putadd(add / 16);
		len += ft_putadd(add % 16);
	}
	return (len);
}
