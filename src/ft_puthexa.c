/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:13:49 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/08 17:17:06 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthexa(unsigned long n)
{
	const char	*hexa = "0123456789ABCDEF";

	if (n)
	{
		ft_puthexa(n / 16);
		ft_putchar(hexa[n % 16]);
	}
}

void	ft_puthexa_formated(unsigned long n, size_t size, bool prefix)
{
	size_t			len;
	unsigned long	tmp;

	tmp = n;
	len = 0;
	while (tmp)
	{
		len++;
		tmp /= 16;
	}
	if (prefix)
		ft_putstr("0x");
	while (size > len)
	{
		ft_putchar('0');
		--size;
	}
	ft_puthexa(n);
}
