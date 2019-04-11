/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:19:59 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/01 17:25:08 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	size_t	ft_splitcount(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static	int		ft_splitlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	len;
	char	**dest;

	if (!s)
		return (NULL);
	len = ft_splitcount(s, c);
	if (!(dest = (char**)malloc(sizeof(*dest) * (len + 1))))
		return (NULL);
	i = 0;
	while (len > 0)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(dest[i] = ft_strsub(s, 0, ft_splitlen(s, c))))
			return (NULL);
		while (*s != c && *s != '\0')
			s++;
		i++;
		len--;
	}
	dest[i] = NULL;
	return (dest);
}
