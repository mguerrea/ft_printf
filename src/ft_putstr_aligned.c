/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_aligned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 16:37:26 by gmichaud          #+#    #+#             */
/*   Updated: 2018/12/08 17:20:45 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_aligned(char const *s, size_t columns)
{
	size_t	len;

	len = 0;
	while (s[len])
		++len;
	write(1, s, len);
	columns -= len;
	while (columns > 0)
	{
		write(1, " ", 1);
		--columns;
	}
}
