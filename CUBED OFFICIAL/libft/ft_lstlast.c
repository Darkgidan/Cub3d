/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarciof <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:38:29 by tcarciof          #+#    #+#             */
/*   Updated: 2021/01/14 16:38:32 by tcarciof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	int		last;
	t_list	*act;

	act = lst;
	if (act == NULL)
		return (NULL);
	else
	{
		last = ft_lstsize(lst);
		while (--last > 0)
			lst = lst->next;
		return (lst);
	}
}
