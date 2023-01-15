/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:25:09 by atouba            #+#    #+#             */
/*   Updated: 2021/11/15 11:26:38 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ans;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	ans = malloc(count * size);
	if (!ans)
		return (0);
	ft_bzero(ans, count * size);
	return (ans);
}

// int main()
// {
// 	ft_calloc(4, 2);
// }