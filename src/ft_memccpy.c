/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 17:25:34 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/16 17:38:10 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*destc;
	unsigned char	*srcc;

	destc = (unsigned char*)dest;
	srcc = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		*destc = *srcc;
		destc = destc + 1;
		if (*srcc == (unsigned char)c)
			return (destc);
		srcc = srcc + 1;
		i++;
	}
	return (NULL);
}
