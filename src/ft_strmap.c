/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 14:52:45 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/22 17:27:53 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*dest;

	dest = NULL;
	if (s)
	{
		if (!(dest = ft_strnew(sizeof(*dest) * (ft_strlen(s)))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			dest[i] = f(s[i]);
			i++;
		}
	}
	return (dest);
}
