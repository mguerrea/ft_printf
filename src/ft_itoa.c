/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 15:37:47 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/01 17:19:05 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_intsize(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len = 1;
	else
	{
		if (n < 0)
			len = 1;
		while (n != 0)
		{
			len++;
			n = n / 10;
		}
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		i;

	len = ft_intsize(n);
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = len - 1;
	if (n < 0)
		s[0] = '-';
	if (n == 0)
		s[i] = '0';
	while (n != 0)
	{
		if (n > 0)
			s[i] = n % 10 + 48;
		if (n < 0)
			s[i] = -(n % 10) + 48;
		n = n / 10;
		i--;
	}
	s[len] = '\0';
	return (s);
}
