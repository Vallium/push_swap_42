/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 18:07:51 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/28 18:07:53 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sort(t_stacks *stacks)
{
	t_list	*tmp;
	int		i;

	if (stacks->nb_sb > 0)
		return (0);
	if (stacks->nb_sa > 1)
	{
		tmp = stacks->sa;
		i = *(int *)tmp->content;
		tmp = tmp->next;
		while (tmp)
		{
			if (i > *(int *)tmp->content)
				return (0);
			i = *(int *)tmp->content;
			tmp = tmp->next;
		}
	}
	return (1);
}

int		is_presk_sort(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*bfr;

	if (stacks->nb_sa > 3 && stacks->nb_sb == 0)
	{
		tmp = stacks->sa;
		bfr = tmp;
		while (tmp->next)
		{
			bfr = tmp;
			tmp = tmp->next;
		}
		tmp->next = bfr;
		bfr->next = 0;
		if (is_sort(stacks))
		{
			bfr->next = tmp;
			tmp->next = 0;
			return (1);
		}
		bfr->next = tmp;
		tmp->next = 0;
	}
	return (0);
}

int		sa_min(t_stacks *stacks, int *ret)
{
	t_list	*tmp;
	int		i;
	int		index;

	*ret = -1;
	i = INT_MAX;
	index = 0;
	tmp = stacks->sa;
	while (tmp)
	{
		if (*((int *)tmp->content) < i)
		{
			i = *(int *)tmp->content;
			*ret = index;
		}
		index++;
		tmp = tmp->next;
	}
	return (i);
}
