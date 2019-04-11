/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_aligned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:55:05 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/08 17:17:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrlu_aligned(unsigned long n, size_t columns)
{
	columns -= ft_nbrlen(n);
	ft_putnbrlu(n);
	while (columns > 0)
	{
		ft_putchar(' ');
		--columns;
	}
}
