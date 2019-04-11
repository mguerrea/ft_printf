/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 18:58:11 by gmichaud          #+#    #+#             */
/*   Updated: 2016/11/08 17:58:15 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t			i;
	unsigned char	*str1c;
	unsigned char	*str2c;

	str1c = (unsigned char*)str1;
	str2c = (unsigned char*)str2;
	i = 0;
	while (i < n)
	{
		if (*str1c != *str2c)
			return (*str1c - *str2c);
		str1c = str1c + 1;
		str2c = str2c + 1;
		i++;
	}
	return (0);
}
