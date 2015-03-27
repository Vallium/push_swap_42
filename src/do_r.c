/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 18:29:49 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/20 18:29:51 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stacks->nb_sa > 1)
	{
		tmp = stacks->sa;
		tmp2 = stacks->sa;
		stacks->sa = stacks->sa->next;
		while(tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = 0;
	}
	print_move(stacks, "RA", "\033[35m");
//	ft_putstr("RA");
	stacks->nb_act++;
}

void	do_rb(t_stacks *stacks)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (stacks->nb_sb > 1)
	{
		tmp = stacks->sb;
		tmp2 = stacks->sb;
		stacks->sb = stacks->sb->next;
		while(tmp2->next)
			tmp2 = tmp2->next;
		tmp2->next = tmp;
		tmp->next = 0;
	}
	print_move(stacks, "RB", "\033[35m");
//	ft_putstr("RB");
	stacks->nb_act++;
}

void	do_rr(t_stacks *stacks)
{
	do_ra(stacks);
	do_rb(stacks);
	stacks->nb_act--;
}
