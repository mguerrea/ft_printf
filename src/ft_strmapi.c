/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 15:14:39 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 16:55:16 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	dest = NULL;
	if (s)
	{
		if (!(dest = ft_strnew(sizeof(*dest) * (ft_strlen(s)))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			dest[i] = f(i, s[i]);
			i++;
		}
	}
	return (dest);
}
