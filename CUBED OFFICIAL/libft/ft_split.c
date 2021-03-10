/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:48:26 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/22 17:48:33 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static unsigned long int		ft_wc(const char *str, char c)
{
	unsigned long int		i;
	unsigned long int		wordc;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == c)
	{
		i++;
		if (str[i] == '\0')
			return (0);
	}
	if (str[i] == '\0')
		return (0);
	wordc = 1;
	while (str[i])
	{
		while (str[i] && (str[i] != c))
			i++;
		while (str[i] && (str[i] == c))
			i++;
		if (str[i])
			wordc++;
	}
	return (wordc);
}

static unsigned long int		ft_wl(const char *str, char c)
{
	unsigned long int		res;

	res = -1;
	while (str[++res] && str[res] != c)
		;
	return (res);
}

char							**ft_split(char const *s, char c)
{
	char						**mat;
	unsigned long int			var[3];

	if (!s)
		return (NULL);
	var[0] = 0;
	var[1] = -1;
	if (!(mat = (char **)malloc(sizeof(char *) * (ft_wc((char *)s, c) + 1))))
		return (NULL);
	while (s[var[0]])
	{
		var[2] = -1;
		while (s[var[0]] == c)
			var[0]++;
		if (s[var[0]] == '\0')
			break ;
		if (!(mat[++var[1]] = (char *)malloc(sizeof(char) *
		(ft_wl(&s[var[0]], c) + 1))))
			return (NULL);
		while (s[var[0]] != c && s[var[0]])
			mat[var[1]][++var[2]] = s[var[0]++];
		mat[var[1]][++var[2]] = '\0';
	}
	mat[++var[1]] = NULL;
	return (mat);
}
