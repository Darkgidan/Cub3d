/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:40:13 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:40:14 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	act;
	size_t			i;
	unsigned char	*p;

	i = -1;
	p = (unsigned char *)b;
	act = c % 256;
	while (++i < len)
		p[i] = act;
	return (b);
}
