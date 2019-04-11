/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/16 12:34:01 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/15 17:00:49 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlentrim(char const *s)
{
	size_t len;
	size_t i;
	size_t j;

	len = ft_strlen(s);
	j = len;
	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		len--;
		i++;
	}
	if (len > 0)
	{
		while (j > 0 && (s[j - 1] == ' ' || s[j - 1] == '\n'
				|| s[j - 1] == '\t'))
		{
			len--;
			j--;
		}
	}
	return (len);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*dest;

	dest = NULL;
	if (s)
	{
		len = ft_strlentrim(s);
		if (!(dest = ft_strnew(sizeof(*dest) * (len))))
			return (NULL);
		i = 0;
		while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
			i++;
		j = 0;
		while (j < len)
		{
			dest[j] = s[i];
			i++;
			j++;
		}
		dest[j] = '\0';
	}
	return (dest);
}
