/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 09:21:47 by gmichaud          #+#    #+#             */
/*   Updated: 2017/03/31 13:07:09 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t o_size, size_t n_size)
{
	void	*new;

	if (n_size == 0)
	{
		ft_memdel(&ptr);
		return (NULL);
	}
	if (!(new = ft_memalloc(n_size)))
		return (NULL);
	if (ptr && o_size)
	{
		if (o_size > n_size)
			ft_memcpy(new, ptr, n_size);
		else
			ft_memcpy(new, ptr, o_size);
		ft_memdel(&ptr);
	}
	return (new);
}
