/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megadiou <megadiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:12:22 by megadiou          #+#    #+#             */
/*   Updated: 2023/11/08 16:37:53 by megadiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		head = ft_lstnew(content);
		if (!head)
		{
			del(head);
			ft_lstclear(&new, del);
			return (new);
		}
		ft_lstadd_back(&new, head);
		lst = lst->next;
	}
	return (new);
}
