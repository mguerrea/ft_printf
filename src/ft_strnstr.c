/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 17:07:45 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/16 15:47:01 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*ptr;

	ptr = NULL;
	i = 0;
	k = 0;
	if (need[0] == '\0')
		return ((char*)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		i = k;
		ptr = (char*)hay + k;
		while (hay[i] && need[j] && i < len && hay[i] == need[j])
		{
			j++;
			i++;
		}
		if (need[j] == '\0')
			return (ptr);
		k++;
	}
	return (NULL);
}
