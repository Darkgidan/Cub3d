/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:43:36 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:43:38 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		act;
	char		*p;
	int			i;
	int			last;

	last = -1;
	p = (char *)s;
	i = -1;
	act = c % 128;
	while (p[++i])
	{
		if (p[i] == act)
			last = i;
	}
	if (s[i] == act)
		return (&p[i]);
	else if (last != -1)
		return (&p[last]);
	return ((char *)0);
}
