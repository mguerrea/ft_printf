/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbouchet <hbouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 18:39:31 by hbouchet          #+#    #+#             */
/*   Updated: 2018/03/19 18:39:32 by hbouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp1;
	t_list *tmp2;

	if (alst)
	{
		tmp1 = *alst;
		tmp2 = tmp1;
		while (tmp1)
		{
			tmp1 = tmp1->next;
			del(tmp2->content, tmp2->content_size);
			free(tmp2);
			tmp2 = tmp1;
		}
		*alst = NULL;
	}
}
