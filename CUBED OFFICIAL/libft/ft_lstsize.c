/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:39:07 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:39:08 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		dim;
	t_list	*act;

	dim = 0;
	act = lst;
	if (!act)
		return (0);
	while (act)
	{
		act = act->next;
		dim++;
	}
	return (dim);
}
