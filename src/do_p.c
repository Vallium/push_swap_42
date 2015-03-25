/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 18:30:01 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/20 18:30:03 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->nb_sb > 0)
	{
		tmp = stacks->sb;
		stacks->sb = stacks->sb->next;
		tmp->next = stacks->sa;
		stacks->sa = tmp;
		stacks->nb_sa++;
		stacks->nb_sb--;
		}
	ft_putstr("PA ");
	stacks->nb_act++;
}

void	do_pb(t_stacks *stacks)
{
	t_list	*tmp;

	if (stacks->nb_sa > 0)
	{
		tmp = stacks->sa;
		stacks->sa = stacks->sa->next;
		tmp->next = stacks->sb;
		stacks->sb = tmp;
		stacks->nb_sa--;
		stacks->nb_sb++;
	}
	ft_putstr("PB ");
	stacks->nb_act++;
}
