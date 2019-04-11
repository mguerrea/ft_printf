/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:48:00 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 17:45:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*strc;
	unsigned char	c1;

	c1 = (unsigned char)c;
	strc = (unsigned char*)str;
	while (n--)
	{
		if (*strc == c1)
			return (strc);
		strc++;
	}
	return (NULL);
}
