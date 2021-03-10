/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:42:21 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/19 17:28:46 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dim;
	char	*p;

	p = (char *)dst;
	dim = -1;
	i = ft_strlen(dst);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[++dim] && dim + i < dstsize - 1)
		p[i + dim] = src[dim];
	p[i + dim] = '\0';
	dim = ft_strlen(src);
	if (i < dstsize)
		return (i + dim);
	else
		return (dstsize + dim);
}
