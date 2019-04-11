/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 17:10:45 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 16:58:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	c1;
	int		len;

	c1 = (char)c;
	len = 0;
	while (*s)
	{
		len++;
		s++;
	}
	while (len >= 0)
	{
		if (*s == c1)
			return ((char*)s);
		s--;
		len--;
	}
	return (NULL);
}
