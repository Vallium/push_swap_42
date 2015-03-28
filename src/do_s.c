/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 18:30:11 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/20 18:30:13 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa(t_stacks *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stacks->nb_sa > 2)
	{
		tmp1 = stacks->sa;
		tmp2 = stacks->sa->next;
		tmp3 = stacks->sa->next->next;
		stacks->sa->next = tmp2->next;
		stacks->sa = tmp2;
		tmp2->next = tmp1;
		tmp1->next = tmp3;
	}
	else if (stacks->nb_sa == 2)
	{
		tmp1 = stacks->sa->next;
		stacks->sa->next = 0;
		tmp1->next = stacks->sa;
		stacks->sa = tmp1;
	}
	print_move(stacks, "SA", "\033[32m");
	stacks->nb_act++;
}

void	do_sb(t_stacks *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stacks->nb_sb > 2)
	{
		tmp1 = stacks->sb;
		tmp2 = stacks->sb->next;
		tmp3 = stacks->sb->next->next;
		stacks->sb->next = tmp2->next;
		stacks->sb = tmp2;
		tmp2->next = tmp1;
		tmp1->next = tmp3;
	}
	else if (stacks->nb_sb == 2)
	{
		tmp1 = stacks->sb->next;
		stacks->sb->next = 0;
		tmp1->next = stacks->sb;
		stacks->sb = tmp1;
	}
	print_move(stacks, "SB", "\033[32m");
	stacks->nb_act++;
}

void	do_ss(t_stacks *stacks)
{
	do_sa(stacks);
	do_sb(stacks);
	stacks->nb_act--;
}
