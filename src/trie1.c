/*
 * trie1.c
 *
 *  Created on: 21 mars 2015
 *      Author: spectrenoir
 */

#include "push_swap.h"
#include <limits.h>


static void	min(t_stacks *stacks)
{
	int i = INT_MAX;
	t_list *tmp = stacks.sa;
	while (tmp)
	{
		if (*tmp.content < i)
			i = *tmp.content;
		tmp = tmp->next;
	}
}

void	trie(t_stacks *stacks)
{

}
