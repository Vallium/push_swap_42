/*
 * trie1.c
 *
 *  Created on: 21 mars 2015
 *      Author: spectrenoir
 */

#include "push_swap.h"
#include <limits.h>


static int	lstmin(t_stacks *stacks)
{
	int i = INT_MAX;
	t_list *tmp = stacks->sa;
	while (tmp)
	{
		if (*((int *)tmp->content) < i)
			i = *(int *)tmp->content;
		tmp = tmp->next;
	}
	return (i);
}

void	trie(t_stacks *stacks)
{
	int min;

	while (stacks->nb_sa > 0)
	{
		min = lstmin(stacks);
		while (*(int *)stacks->sa->content != min)
			do_ra(stacks);
		do_pb(stacks);
	}
	while (stacks->nb_sb)
		do_pa(stacks);

}
