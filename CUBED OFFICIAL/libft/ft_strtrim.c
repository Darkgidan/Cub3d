/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:43:59 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/20 11:13:41 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(char const str, char const *set)
{
	unsigned long int	i;

	i = -1;
	while (set[++i] != str && set[i])
		;
	if (set[i] == str)
		return (1);
	return (0);
}

static int		ft_trimend(const char *set, const char *ori)
{
	unsigned long int		dimset;
	unsigned long int		i;

	dimset = ft_strlen(set);
	i = ft_strlen(ori);
	while (ft_isset(ori[--i], set) == 1)
		;
	return (i);
}

static int		ft_trimstart(const char *set, const char *ori)
{
	unsigned long int		dimset;
	unsigned long int		i;

	dimset = ft_strlen(set);
	i = -1;
	while (ft_isset(ori[++i], set) == 1)
		;
	return (i);
}

char			*ft_strtrim(char const *str, char const *set)
{
	int		end;
	int		start;
	char	*p;
	int		i;

	if (!str)
		return ((char *)0);
	end = ft_trimend(set, str);
	start = ft_trimstart(set, str);
	if (end <= start)
		return (ft_strdup(""));
	if (!(p = malloc(sizeof(char) * ((end - start + 2)))))
		return (NULL);
	i = -1;
	while (++i < end - start + 1)
		p[i] = str[i + start];
	p[i] = '\0';
	return (p);
}
