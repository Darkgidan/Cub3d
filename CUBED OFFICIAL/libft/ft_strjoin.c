/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:42:06 by tcarciof          #+#    #+#             */
/*   Updated: 2021/02/23 18:25:06 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	if (!(p = (char *)malloc(sizeof(char) * (i + j + 2))))
		return ((char *)0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	return (p);
}

char	*ft_strjoin1(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	if (!(p = (char *)malloc(sizeof(char) * (i + j + 2))))
		return ((char *)0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s1);
	return (p);
}

char	*ft_strjoin2(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	if (!(p = (char *)malloc(sizeof(char) * (i + j + 2))))
		return ((char *)0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s2);
	return (p);
}

char	*ft_strjoin3(char const *s1, char const *s2)
{
	char		*p;
	size_t		i;
	size_t		j;
	size_t		act;

	if (!s1 || !s2)
		return ((char *)0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	act = -1;
	if (!(p = (char *)malloc(sizeof(char) * (i + j + 2))))
		return ((char *)0);
	while (++act < i)
		p[act] = s1[act];
	while (++act < i + j + 1)
		p[act - 1] = s2[act - i - 1];
	p[act - 1] = '\0';
	free((char *)s1);
	free((char *)s2);
	return (p);
}