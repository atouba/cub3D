/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 18:38:40 by atouba            #+#    #+#             */
/*   Updated: 2021/11/13 18:34:54 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_list;

	new_list = malloc(sizeof(t_list));
	if (!new_list)
		return (0);
	new_list->content = content;
	new_list->next = 0;
	return (new_list);
}
// int main()
// {
// 	char s[] = "hello world";
// 	t_list *root;
// 	root = ft_lstnew((void *)s);
// 	printf("%s", (char *)root->content);
// }