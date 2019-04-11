/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:26:25 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/23 17:14:45 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t len;
	size_t i;

	len = 0;
	while (dest[len] && len < n)
		len++;
	i = 0;
	if (n)
	{
		while (len + i < n - 1 && src[i])
		{
			dest[len + i] = src[i];
			i++;
		}
		if (len < n)
			dest[len + i] = '\0';
	}
	return (len + ft_strlen(src));
}
