/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <tcarciof@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:36:57 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/19 17:32:21 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_check(int *n, char *p, int *op, long int *div)
{
	if (*n == -2147483648)
	{
		p[0] = '-';
		p[1] = '2';
		*n = 147483648;
		*div /= 10;
		*op = 1;
	}
	else if (*n < 0)
	{
		p[0] = '-';
		*n = (*n) * -1;
		*op = 0;
	}
}

static void			ft_fix(char *p, int div)
{
	int fixi;

	fixi = 0;
	while (div > 0)
	{
		p[fixi + 1] = 48;
		fixi++;
		div /= 10;
	}
	p[fixi + 1] = 0;
}

static char			*ft_zero(void)
{
	char *p;

	if (!(p = (char *)malloc(sizeof(char) * (2))))
		return ((char *)0);
	p[0] = '0';
	p[1] = '\0';
	return (p);
}

static int			ft_abs(int n)
{
	if (n >= 0)
		return (n);
	else
		return (-n);
}

char				*ft_itoa(int n)
{
	char			*p;
	long int		maxdiv;
	int				dim;
	int				op;

	maxdiv = 1;
	dim = 0;
	op = -1;
	while (ft_abs(n / (maxdiv * 10)) > 0 && ++dim)
		maxdiv *= 10;
	if (n == 0)
		return (ft_zero());
	if (!(p = (char *)malloc(sizeof(char) * (dim + 3))))
		return ((char *)0);
	ft_check(&n, p, &op, &maxdiv);
	while (n > 0)
	{
		p[++op] = (char)((n / maxdiv) + 48);
		n -= (n / maxdiv) * maxdiv;
		maxdiv /= 10;
	}
	ft_fix(&p[op], maxdiv);
	return (p);
}
