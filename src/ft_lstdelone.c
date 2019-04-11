/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:19:17 by gmichaud          #+#    #+#             */
/*   Updated: 2016/12/01 17:19:22 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list *tmp;

	if (alst)
	{
		tmp = *alst;
		del(tmp->content, tmp->content_size);
		free(tmp);
		*alst = NULL;
		tmp = NULL;
	}
}
