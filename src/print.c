/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalliot <aalliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/28 18:07:31 by aalliot           #+#    #+#             */
/*   Updated: 2015/03/28 18:07:33 by aalliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move(t_stacks *st, char *str, char *color)
{
	if (st->nb_act && !(st->options & 8))
	{
		ft_putchar(' ');
	}
	if (st->options & 2)
		ft_putstr(color);
	ft_putstr(str);
	ft_putstr("\033[37m");
	if (st->options & 8)
	{
		ft_putchar('\n');
		print_stacks(st);
	}
}

void	print_acts_nb(int i, t_stacks all)
{
	if (all.options & 2)
		ft_putstr("\033[33m");
	ft_putstr("Number of actions");
	ft_putstr("\033[0m = ");
	if (all.options & 2)
		ft_putstr("\033[32m");
	ft_putnbr(i);
	ft_putstr("\033[37m\n\n");
}

void	illegal_option(t_opt *opt)
{
	ft_putstr_fd("push_swap: illegal option -- ", 2);
	ft_putchar_fd(opt->err, 2);
	ft_putchar_fd('\n', 2);
	exit (2);
}
