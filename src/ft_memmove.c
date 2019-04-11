/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:21:50 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 18:00:08 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destc;
	char	*srcc;

	destc = (char*)dest;
	srcc = (char*)src;
	i = 0;
	if (dest > src)
	{
		while (n > 0)
		{
			destc[n - 1] = srcc[n - 1];
			n--;
		}
	}
	else if (dest < src)
	{
		while (i < n)
		{
			destc[i] = srcc[i];
			i++;
		}
	}
	return (dest);
}
