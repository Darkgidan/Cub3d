/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:39:28 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:39:30 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	act;
	unsigned char	*s1;

	s1 = (unsigned char *)s;
	act = c % 256;
	i = -1;
	while (++i < n)
	{
		if (s1[i] == act)
			return (&s1[i]);
	}
	return ((void *)0);
}
