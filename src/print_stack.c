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
	if (st->options & 2)
		ft_putstr("\033[31m");
	ft_putnbr(st->nb_sa);
	ft_putstr("\033[37m");
	ft_putstr(st->nb_sa > 1 ? " elements): " : " element):  ");
	if (!tmp)
		ft_putstr("NULL");
	while (tmp)
	{
		if (st->options & 2)
			ft_putstr("\033[33m");
		ft_putnbr(*((int *)tmp->content));
		ft_putstr("\033[37m");
		if (tmp->next)
			ft_putstr(" -> ");
		tmp = tmp->next;
	}
}

void	print_stack_b(t_stacks *st)
{
	t_list *tmp;

	tmp = st->sb;
	ft_putstr("Stack B (");
	if (st->options & 2)
		ft_putstr("\033[31m");
	ft_putnbr(st->nb_sb);
	ft_putstr("\033[37m");
	ft_putstr(st->nb_sb > 1 ? " elements): " : " element):  ");
	if (!tmp)
		ft_putstr("NULL");
	while (tmp)
	{
		if (st->options & 2)
			ft_putstr("\033[33m");
		ft_putnbr(*((int *)tmp->content));
		ft_putstr("\033[37m");
		if (tmp->next)
			ft_putstr(" -> ");
		tmp = tmp->next;
	}
}

void	print_stacks(t_stacks *st)
{
	print_stack_a(st);
	ft_putchar('\n');
	print_stack_b(st);
	ft_putchar('\n');
	ft_putstr("\033[0m");
}
