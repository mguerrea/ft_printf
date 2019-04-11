/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:41:50 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 16:37:56 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n >= -9 && n <= 9)
	{
		if (n < 0)
			n = -n;
		ft_putchar_fd(n + 48, fd);
	}
	if (n < -9)
	{
		ft_putnbr_fd(n / -10, fd);
		ft_putnbr_fd(-(n % 10), fd);
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
}
