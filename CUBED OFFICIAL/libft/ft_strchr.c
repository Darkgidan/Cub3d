/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:41:41 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/18 18:51:01 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		act;
	char		*p;
	int			i;

	p = (char *)s;
	i = -1;
	act = c % 128;
	while (p[++i])
		if (p[i] == act)
			return (&p[i]);
	if (s[i] == act)
		return (&p[i]);
	return ((char *)0);
}
