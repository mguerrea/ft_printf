/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 18:40:52 by gmichaud          #+#    #+#             */
/*   Updated: 2017/02/02 11:01:14 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void		*mem;
	char		*init;
	size_t		n;

	if (!(init = (char*)malloc(size)))
		return (NULL);
	n = 0;
	while (n < size)
	{
		init[n] = 0;
		n++;
	}
	mem = &init[0];
	return (mem);
}
