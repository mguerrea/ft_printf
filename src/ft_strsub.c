/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 08:57:13 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 16:59:17 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	dest = NULL;
	if (s)
	{
		if (!(dest = ft_strnew(sizeof(*dest) * (len))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			dest[i] = s[start + i];
			i++;
		}
	}
	return (dest);
}
