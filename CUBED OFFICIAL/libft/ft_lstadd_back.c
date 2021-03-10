/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:37:06 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:37:07 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *act;

	if (*lst == NULL)
		*lst = new;
	else
	{
		act = ft_lstlast(*lst);
		if (act != NULL)
			act->next = new;
	}
}
