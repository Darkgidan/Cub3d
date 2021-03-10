/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:43:49 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:43:50 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	char	*s1;
	char	*s2;
	size_t	found;
	size_t	i;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	i--;
	if (!*s2)
		return (&s1[0]);
	while (s1[++i] && i < size)
	{
		found = 0;
		while (s1[found + i] == s2[found] && i + found < size)
		{
			found++;
			if (!s2[found])
				return (&s1[i]);
		}
	}
	return ((char *)0);
}
