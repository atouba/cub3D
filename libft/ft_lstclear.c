/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 00:33:39 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 16:57:44 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;

	if (!lst || !(*lst) || !del)
		return ;
	while (*lst)
	{
		curr = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		*lst = curr;
	}
	lst = 0;
}
