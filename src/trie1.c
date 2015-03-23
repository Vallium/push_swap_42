/*
 * trie1.c
 *
 *  Created on: 21 mars 2015
 *      Author: spectrenoir
 */

#include "push_swap.h"


int		need_sa(t_stacks *st)
{
		if (st->nb_sa > 1)
		{
			return (*(int *)st->sa->content > *(int *)st->sa->next->content);
		}
		return (0);
}

void	trie(t_stacks *stacks)
{
	int min;
	int index;

	while (stacks->nb_sa > 1)
	{
		if (is_sort(stacks))
			return;
		min = sa_min(stacks, &index);
		while (*(int *)stacks->sa->content != min)
		{
			if (is_sort(stacks))
				return;
			if (need_sa(stacks))
				do_sa(stacks);
			else if (index >= (stacks->nb_sa / 2))
				do_rra(stacks);
			else
				do_ra(stacks);
		}
		if (is_sort(stacks))
			return;
		do_pb(stacks);
	}
	while (stacks->nb_sb)
		do_pa(stacks);

}
