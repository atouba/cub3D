/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atouba <atouba@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:42:52 by atouba            #+#    #+#             */
/*   Updated: 2021/11/09 10:52:12 by atouba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
#include "libft.h"

//re test it!
//there was while (i < n) before the 6thline
// is writing one '\0' == filling the string with n '\0'
// while (i < n)
	// {
	// 	*(unsigned char *)(s + i) = '\0';
	// 	i++;
	// }
void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
	{
		ft_memset(s, '\0', n);
	}
}
// int main()
// {
// 	char x[] = "hello there";
// 	char y[] = "hello there";
// 	bzero(x + 4, 2 * sizeof(char));
// 	ft_bzero(y + 4, 2);
// //	printf("%s", x);
// 	printf("%s", y);
// }