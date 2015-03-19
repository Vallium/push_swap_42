/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelnode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/15 19:34:08 by aalliot           #+#    #+#             */
/*   Updated: 2015/02/15 19:34:10 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	ft_lstdelnode(t_list **node)
{
	if ((*node)->next != NULL)
	{
		(*node)->content = (*node)->next->content;
		(*node)->content_size = (*node)->next->content_size;
		(*node)->next = (*node)->next->next;
	}
	else
		*node = NULL;
}
