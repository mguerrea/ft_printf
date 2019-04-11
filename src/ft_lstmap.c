/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:43:08 by gmichaud          #+#    #+#             */
/*   Updated: 2017/01/13 18:55:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *lst2;
	t_list *tmp2;
	t_list *new;

	tmp = lst;
	new = NULL;
	if (lst == NULL)
		return (NULL);
	if (!(lst2 = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	lst2 = f(lst2);
	tmp2 = lst2;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		new = f(new);
		ft_lstpush_back(&tmp2, new);
		tmp2 = new;
		tmp = tmp->next;
	}
	return (lst2);
}
