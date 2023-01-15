/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:07:19 by atouba            #+#    #+#             */
/*   Updated: 2021/11/21 17:10:31 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!(s) || fd < 0)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}

// int main()
// {
// 	char a[] = "hello";
// 	ft_putstr_fd(a, 1);
// }