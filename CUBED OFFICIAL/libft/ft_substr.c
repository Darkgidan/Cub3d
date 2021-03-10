/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:44:13 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/19 18:53:02 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*p;
	unsigned long int	dim;
	unsigned long int	i;
	unsigned long int	dstart;

	i = -1;
	if (!s)
		return ((char *)0);
	if (len == 0)
		return (ft_strdup(""));
	dim = ft_strlen(s);
	if (start >= dim)
		return (ft_calloc(sizeof(char), 2));
	dstart = start--;
	if (!(p = (char *)malloc(sizeof(char) * (len + 1))))
		return ((char *)0);
	while (++start >= 0 && ++i < len && start - dstart < len)
		p[i] = s[start];
	p[i] = '\0';
	return (p);
}
