/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/25 23:17:09 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/25 23:17:13 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_stacks *st)
{
	t_list *tmp;

	tmp = st->sa;
	ft_putstr("Stack A (");
	ft_putnbr(st->nb_sa);
	ft_putstr("elements): ");
	if (!tmp)
		ft_putstr(" NULL\n");
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(*((int *)tmp->content));
		if (tmp->next)
			ft_putstr(" ->");
		tmp = tmp->next;
	}
}

void	print_stack_b(t_stacks *st)
{
	t_list *tmp;

	tmp = st->sb;
	ft_putstr("Stack B (");
	ft_putnbr(st->nb_sb);
	ft_putstr("elements): ");
	if (!tmp)
		ft_putstr(" NULL\n");
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(*((int *)tmp->content));
		if (tmp->next)
			ft_putstr(" ->");
		tmp = tmp->next;
	}
}

void	print_stacks(t_stacks *st)
{
	print_stack_a(st);
	printf("\n");
	print_stack_b(st);
	ft_putchar('\n');
}

