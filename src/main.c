/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 12:01:20 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/19 12:02:42 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

void	do_sa(t_stacks *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stacks->nb_sa > 2)
	{
		tmp1 = stacks->sa;
		tmp2 = stacks->sa->next;		//memorise 2e elem
		tmp3 = stacks->sa->next->next;

		stacks->sa->next = tmp2->next;	//1er pointe vers le 3e
		stacks->sa = tmp2; 				// debut pointe vers le 2e
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
}

void	do_sb(t_stacks *stacks)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	if (stacks->nb_sb > 2)
	{
		tmp1 = stacks->sb;
		tmp2 = stacks->sb->next;		// memorise 2e elem
		tmp3 = stacks->sb->next->next;

		stacks->sb->next = tmp2->next;	// 1er pointe vers le 3e
		stacks->sb = tmp2;				// debut pointe vers le 2e
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
}

void	do_pa(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->sb;
	stacks->sb = stacks->sb->next;
	tmp->next = stacks->sa;
	stacks->sa = tmp;
	stacks->nb_sa++;
	stacks->nb_sb--;
}

void	do_pb(t_stacks *stacks)
{
	t_list	*tmp;

	tmp = stacks->sa;
	stacks->sa = stacks->sa->next;
	tmp->next = stacks->sb;
	stacks->sb = tmp;
	stacks->nb_sa--;
	stacks->nb_sb++;
}

/*
void	do_rrr(t_stacks *stacks)
{
	do_rra(stacks);
	do_rrb(stacks);
}

void	do_rr(t_stacks *stacks)
{
	do_ra(stacks);
	do_rb(stacks);
}
*/

void	do_ss(t_stacks *stacks)
{
	do_sa(stacks);
	do_sb(stacks);
}

void	print_stacks(t_stacks *st)
{
	t_list *tmp;

	tmp = st->sa;
	printf("Pile A (%d elems): ", st->nb_sa);
	while (tmp)
	{
		printf(" %d ->",*((int *)tmp->content));
		tmp = tmp->next;
	}
	printf(" NULL\n");

	tmp = st->sb;
	printf("Pile B (%d elems): ", st->nb_sb);
	while (tmp)
	{
		printf(" %d ->",*((int *)tmp->content));
		tmp = tmp->next;
	}
	printf(" NULL\n\n");
}

int		main()
{
	int data1 = 1;
	int data2 = 2;
	int data3 = 3;
	int data4 = 4;
	int data5 = 5;

	t_list	elem1;
	t_list	elem2;
	t_list	elem3;
	t_list	elem4;
	t_list	elem5;

	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = &elem5;
	elem5.next = 0;

	elem1.content = &data1;
	elem2.content = &data2;
	elem3.content = &data3;
	elem4.content = &data4;
	elem5.content = &data5;

	t_stacks test;

	test.nb_sa = 5;
	test.nb_sb = 0;

	test.sa = &elem1;
	test.sb = 0;

	print_stacks(&test);

//	do_sa(&test);
	do_pb(&test);

	print_stacks(&test);
	do_pb(&test);
	print_stacks(&test);
	do_pb(&test);
	print_stacks(&test);
	do_sa(&test);
//	do_pa(&test);
//	do_pa(&test);

	print_stacks(&test);
	return (0);
}
