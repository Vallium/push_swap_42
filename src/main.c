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
	do_pb(&test);
	do_pb(&test);
//	do_sa(&test);
//	do_pa(&test);
//	do_pa(&test);
	print_stacks(&test);
	do_rrr(&test);
	//	do_rr(&test);

	print_stacks(&test);
	return (0);
}
