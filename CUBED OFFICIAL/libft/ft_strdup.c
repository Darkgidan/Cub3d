/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:41:53 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/19 18:50:39 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*p;
	size_t			dim;
	size_t			i;

	i = -1;
	dim = ft_strlen(s1);
	if (!(p = (char *)malloc(sizeof(char) * (dim + 1))))
		return (NULL);
	while (++i < dim)
		p[i] = s1[i];
	p[i] = '\0';
	return (p);
}
