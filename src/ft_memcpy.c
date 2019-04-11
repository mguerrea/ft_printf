/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:23:42 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 17:58:36 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*destc;
	char	*srcc;

	srcc = (char*)src;
	destc = (char*)dest;
	i = 0;
	while (i < n)
	{
		destc[i] = srcc[i];
		i++;
	}
	return (dest);
}
