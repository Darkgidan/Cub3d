/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:16 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/18 12:58:48 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char					*s;
	int						i;
	int						sign;
	unsigned long long int	res;

	res = 0;
	s = (char *)str;
	i = 0;
	sign = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if ((s[i] == 45) || (s[i] == 43))
	{
		if (s[i] == 45)
			sign = 1;
		i++;
	}
	i--;
	while (s[++i] >= '0' && s[i] <= '9')
		res = res * 10 + (s[i] - 48);
	if (res >= 9223372036854775808ULL)
		return (sign == 1 ? 0 : -1);
	if (sign)
		return (((int)(res)) * -1);
	return ((int)res);
}
